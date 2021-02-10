#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QDebug>
#include <QSqlQuery>
#include "messagetile.h"
#include <QColorDialog>
#include <QFontDialog>
#include "brow.h"
QSqlQuery *query;
MessageTile *m;
QString imgPath="";
QFontDialog *fontDialog;
QColorDialog *colorDialog;
int bqindex=0;
Brow *b;
Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    colorDialog = new QColorDialog(this);
    fontDialog = new QFontDialog(this);
    colorDialog->setCurrentColor( QColor(Qt::black) );
    fontDialog->setCurrentFont(ui->messageTextEdit->font());
    m = new MessageTile();
    this->sname = sname;
    ui->userTableWidget->setColumnCount(3);
    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket->bind(port,QUdpSocket::ShareAddress
              |QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,
                       SLOT(processPendingDatagrams()));

    sendMessage(NewParticipant,"");//新用户上线

    //TcpServer是tcpserver.ui对应的类，上面直接用QUdpSocket是因为没有单独的udpserver.ui类
    server = new TcpServer(this);
    //sendFileName()函数一发送，则触发槽函数getFileName()
    connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileName(QString)));

}

Widget::~Widget()
{
    delete ui;
}
void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress,QString sname)
{
    //此处的findItems表示找到与内容localHostName匹配的item，其匹配是基于变体的匹配模式
    bool isEmpty = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty();
    if (isEmpty) {    //没有找到相应的主机名
        //新建3个小的item，分别为user,host,ip

        QTableWidgetItem *user = new QTableWidgetItem(QIcon(getImg(sname)),sname);

        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
        ui->userTableWidget->insertRow(0);//先设置的是第0行，即新来的用户放在最上面
        ui->userTableWidget->setItem(0,0,user);//第0行的第1列...
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);
        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        //arg为返回后面文本的一个副本,%1表示输出的内容按照第1个.arg后面的输出？
        ui->messageBrowser->append(tr("%1 进入了聊天室..！").arg(sname));
        ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));//在线人数为条目的行数
        m->setMsg("上线消息",QString("%0上线了").arg(sname),"");
        m->showAsQQ();
        sendMessage(NewParticipant,"");//该句的功能是让新来的用户也能收到其它在线用户的信息，可拥于更新自己的好友列表
    }
}
void Widget::participantLeft(QString userName, QString localHostName, QString time,QString sname)
{
    //找到第一个对应的主机名
    int rowNum = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);    //此句执行完后，rowCount()内容会自动减1
    ui->messageBrowser->setTextColor(Qt::gray);//设置文本颜色为灰色
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    ui->messageBrowser->append(tr("%1 于 %2 离开！").arg(sname).arg(time));
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}
void Widget::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    out << type << getUserName() << localHostName;

    switch(type)
    {
    case Message :
    {
        if (ui->messageTextEdit->toPlainText() == "")
        {
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out << address<<sname<< getMessage();
        ui->messageBrowser->verticalScrollBar()
                ->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;
    }

    case NewParticipant :
    {
        out << address<<sname;
        break;
    }
    case ParticipantLeft :
    {
        qDebug()<<"qqqq";
        out<<sname;
        break;
    }

    case FileName :
    {
        int row = ui->userTableWidget->currentRow();//必须选中需要发送的给谁才可以发送
        QString clientAddress = ui->userTableWidget->item(row, 2)->text();//（row,,2）为ip地址
        out << address << clientAddress << fileName;//发送本地ip，对方ip，所发送的文件名
        break;
    }
    case Refuse :
    {
        out << serverAddress;
        break;
    }
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);//广播发送
}

void Widget::hasPendingFile(QString userName, QString serverAddress, QString clientAddress, QString fileName)
{
    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,tr("接受文件"),
                                           tr("来自%1(%2)的文件：%3,是否接收？")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);//弹出一个窗口
        if (btn == QMessageBox::Yes) {
            QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);//name为另存为的文件名
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);    //客户端设置文件名
                client->setHostAddress(QHostAddress(serverAddress));    //客户端设置服务器地址
                client->show();
            }
        } else {
            sendMessage(Refuse, serverAddress);
        }
    }
}

//void Widget::closeEvent(QCloseEvent *)
//{
//   on_pushButton_2_clicked();
//}

QString Widget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();//此处的所有地址是指ipv4和ipv6的地址
        //foreach (variable, container),此处为按照容器list中条目的顺序进行迭代
        foreach (QHostAddress address, list) {
            if(address.protocol() == QAbstractSocket::IPv4Protocol)
                return address.toString();
        }
        return 0;
}

QString Widget::getUserName()
{
    QStringList envVariables;
    //将后面5个string存到envVariables环境变量中
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    //系统中关于环境变量的信息存在environment中
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        //indexOf为返回第一个匹配list的索引,QRegExp类是用规则表达式进行模式匹配的类
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            //stringList中存的是environment.at(index)中出现'='号前的字符串
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                return stringList.at(1);//at(0)为文字"USERNAME."，at(1)为用户名
                break;
            }
        }
    }
    return "unknown";

}

QString Widget::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();//转化成html语言进行发送

        ui->messageTextEdit->clear();//发送完后清空输入框
        ui->messageTextEdit->setFocus();//重新设置光标输入焦点，即焦点保持不变
        return msg;
}

QString Widget::getImg(QString username)
{
    query = new QSqlQuery;
    bool ok = query->exec("select *from  user");
    while(query->next())
    {
        QString sname=query->value("username").toString();
        QString imgpath=query->value("imgname").toString();
        if(sname==username)
        {
            return imgpath;
        }
    }
    return "";
}

void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        //pendingDatagramSize为返回第一个在等待读取报文的size，resize函数是把datagram的size归一化到参数size的大小一样
        datagram.resize(udpSocket->pendingDatagramSize());
        //将读取到的不大于datagram.size()大小数据输入到datagram.data()中，datagram.data()返回的是一个字节数组中存储
        //数据位置的指针
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);//因为其属性为只读，所以是输入
        int messageType;    //此处的int为qint32，在Qt中，qint8为char，qint16为uint
        in >> messageType;    //读取1个32位长度的整型数据到messageTyep中
        QString userName,localHostName,ipAddress,message,sname;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");//将当前的时间转化到括号中的形式

        switch(messageType)
        {
        case Message:
        {
            //in>>后面如果为Qstring，则表示读取一个直到出现'\0'的字符串
            in >> userName >> localHostName >> ipAddress >>sname>> message;
            ui->messageBrowser->setTextColor(Qt::blue);//设置文本颜色
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));//设置字体大小

            //输出的格式为用户名加时间显示
            ui->messageBrowser->append("[ " +sname+" ] "+ time);
//            QString str(" < Hello Qt!>\n");
//            QColor  clrR(255,0,0);
//            stringToHtmlFilter(str);
//            stringToHtml(str,clrR);
//            ui->messageBrowser->insertHtml(str);
            ui->messageBrowser->append(message);//消息输出
            break;
        }
        case NewParticipant:

        {
            in >>userName >>localHostName >>ipAddress>>sname;
            newParticipant(userName,localHostName,ipAddress,sname);
            break;
        }
        case ParticipantLeft:
        {
            in >>userName >>localHostName>>sname;
            m->close();
            MessageTile *m = new MessageTile();
            m->setMsg("下线消息",QString("%0下线了").arg(sname),"");
            m->showAsQQ();
            participantLeft(userName,localHostName,time,sname);
            break;
        }
        case FileName:
        {
            in >> userName >> localHostName >> ipAddress;
            QString clientAddress, fileName;
            in >> clientAddress >> fileName;
            hasPendingFile(userName, ipAddress, clientAddress, fileName);
            break;
        }

        case Refuse:
        {
            in >> userName >> localHostName;
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = getIP();

            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
        }
    }
}

void Widget::getFileName(QString name)
{
    fileName = name;
    sendMessage(FileName);

}



void Widget::on_pushButton_clicked()
{
    sendMessage(Message);
}

void Widget::on_sendfile_clicked()
{
    if(ui->userTableWidget->selectedItems().isEmpty())//传送文件前需选择用户
       {
           QMessageBox::warning(0, tr("选择用户"),
                          tr("请先从用户列表选择要传送的用户！"), QMessageBox::Ok);
           return;
       }
       server->show();
       server->initServer();
}

void Widget::on_pushButton_2_clicked()
{
    sendMessage(ParticipantLeft);
    this->close();
}

void Widget::stringToHtmlFilter(QString &str)
  {
  //注意这几行代码的顺序不能乱，否则会造成多次替换
  str.replace("&","&amp;");
  str.replace(">","&gt;");
  str.replace("<","&lt;");
  str.replace("\"","&quot;");
  str.replace("\'","&#39;");
  str.replace(" ","&nbsp;");
  str.replace("\n","<br>");
  str.replace("\r","<br>");
   }
   //根据html标记语言，将QString转化。
void Widget::stringToHtml(QString &str,QColor crl)
{
    QByteArray array;
    array.append(crl.red());
    array.append(crl.green());
    array.append(crl.blue());
    QString strC(array.toHex());
    str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
}
void Widget::imgPathToHtml(QString &path)
{
    path = QString("<img src=\"%1\"/>").arg(path);
}

//设置字体颜色
void Widget::on_pushButton_3_clicked()
{
    if(QDialog::Accepted == colorDialog->exec())
    {
        ui->messageTextEdit->setTextColor(colorDialog->currentColor());
        int rgbred = colorDialog->currentColor().red();
        int rgbgreen = colorDialog->currentColor().green();
        int rgbblue = colorDialog->currentColor().blue();
        ui->pushButton_3->setStyleSheet(QString("color: rgb(%1,%2,%3)").arg(rgbred)
                                        .arg(rgbgreen).arg(rgbblue));
    }
}
//设置字体大小
void Widget::on_pushButton_4_clicked()
{
    fontDialog->setModal(true);
    if(QDialog::Accepted == fontDialog->exec())
    {
        ui->messageTextEdit->setCurrentFont(fontDialog->currentFont());
        ui->pushButton_4->setFont(fontDialog->currentFont());
    }
}
//输入栏事件
void Widget::on_messageTextEdit_currentCharFormatChanged(const QTextCharFormat &format)
{
    ui->messageTextEdit->setTextColor(colorDialog->currentColor());
    ui->messageTextEdit->setCurrentFont(fontDialog->currentFont());
}

//表情按钮
void Widget::on_pushButton_5_clicked()
{
    if(bqindex==0)
    {
        ui->pushButton_5->setStyleSheet("border-image: url(://qqexpression/14.gif)");
        b = new Brow(this);
        connect(b,SIGNAL(mousepress()),this,SLOT(imginsert()));
        b->setGeometry(ui->pushButton_5->x(),ui->pushButton_5->y()-270,270,270);
        b->show();
        bqindex=1;
    }else
    {
        ui->pushButton_5->setStyleSheet("border-image: url(://qqexpression/16.gif)");
        //b->setGeometry(ui->pushButton_5->x(),ui->pushButton_5->y()-270,270,270);
        b->hide();
        bqindex=0;

    }
}
//点击输入栏
void Widget::on_messageTextEdit_selectionChanged()
{
    if(bqindex==1)
    {
        ui->pushButton_5->setStyleSheet("border-image: url(://qqexpression/16.gif)");
        b->hide();
        bqindex=0;
    }


}
 //图片添加
void Widget::imginsert()
{
    if(b!=NULL)
    {
        QString imgPath = b->imgPath;
        imgPathToHtml(imgPath);
        ui->messageTextEdit->insertHtml(imgPath);
    }
}
