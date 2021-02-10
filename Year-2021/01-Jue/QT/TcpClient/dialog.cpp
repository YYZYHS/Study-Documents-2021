#include "dialog.h"
#include <QMessageBox>
#include <QHostInfo>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
        setWindowTitle(tr("TCP Client"));
        contentListWidget = new QListWidget;
        userNameLabel = new QLabel(tr("name:"));
        userNameLineEdit = new QLineEdit;
        serverIPLabel = new QLabel(tr("IP:"));
        serverIPLineEdit = new QLineEdit;
        portLabel = new QLabel(tr("port:"));
        portLineEdit = new QLineEdit;
        enterBtn = new QPushButton(tr("Enter the chat room!"));
        sendLineEdit = new QLineEdit;
        sendBtn = new QPushButton(tr("Send!"));
        mainLayout = new QGridLayout(this);

        mainLayout->addWidget(userNameLabel,0,0);
        mainLayout->addWidget(userNameLineEdit,0,1);
        mainLayout->addWidget(serverIPLabel,1,0);
        mainLayout->addWidget(serverIPLineEdit,1,1);
        mainLayout->addWidget(portLabel,2,0);
        mainLayout->addWidget(portLineEdit,2,1);
        mainLayout->addWidget(enterBtn,3,0,1,2);
        mainLayout->addWidget(contentListWidget,4,0,1,2);
        mainLayout->addWidget(sendLineEdit,5,0);
        mainLayout->addWidget(sendBtn,5,1);
    //记录当前状态，true表示已经进入聊天室，false表示不在聊天室中，根据status的值判断是进入还是离开聊天室
    status = false;
    port = 8010;
    portLineEdit->setText(QString::number(port));
    //初始化记录IP地址的对象
    serverIP =new QHostAddress();
    //将按钮的点击信号和想要对应的槽函数连接起来
    connect(enterBtn,SIGNAL(clicked()),this,SLOT(slotEnter()));
    connect(sendBtn,SIGNAL(clicked()),this,SLOT(slotSend()));
    //将发送信息按钮设置为不可点击状态
    sendBtn->setEnabled(false);
}

Dialog::~Dialog()
{

}
//当要连接服务端的时候发送connected()信号，触发slotConnected()槽函数
void Dialog::slotConnected()
{
    sendBtn->setEnabled(true);
    enterBtn->setText(tr("离开"));

    int length=0;
    QString msg=userName+tr(":Enter Chat Room");
    if((length=tcpSocket->write(msg.toLatin1(),msg. length()))!=msg. length())
    {
    return;
    }
}
void Dialog::slotEnter()
{
    if(!status){//判断当前状态，是否已经加入到聊天室中
            //获取控件上输入的IP地址
            QString ip = serverIPLineEdit->text();

            if(!serverIP->setAddress(ip)){//判断获取的IP地址是否能够正常被解析
                QMessageBox::information(this,tr("error"),tr("ip error!"));
                return;
            }
            if(userNameLineEdit->text()==""){
                QMessageBox::information(this,tr("error"),tr("userName error!"));
                return;
            }
            userName = userNameLineEdit->text();           
            tcpSocket = new QTcpSocket(this); //初始化Tcp套接字
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
            connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
            connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
            //与TCP服务端进行连接，成功的话会发送connected()信号
            tcpSocket->connectToHost(*serverIP,port);
            //记录当前连接状态,记录为已进入聊天室
            status = true;
        }else{//如果已经连接到了服务端，执行面下的操作
            //保存信息的长度
            int length = 0;
            //定义一条离开聊天室的信息，离开聊天室时要发送这条信息给服务端
            QString msg = userName+tr(":Leave chat Room!");
            //通知服务端，用户离开聊天室了
            //如果发送成功，则会返回信息的长度，通过这种方式来判断，信息是否发送出去了
            if((length = tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
                return;
            }
            //与服务端断开连接后，会发出disconnected()信号
            tcpSocket->disconnectFromHost();
            //保存当前状态，记录为已经离开聊天室
            status = false;
        }
}
void Dialog::slotSend()
{
    if(sendLineEdit->text()=="")
    {
        return;
    }
    QString msg=userName+":"+sendLineEdit->text();
    tcpSocket->write(msg.toLatin1(),msg.length());
    sendLineEdit->clear();
}
//当与服务端断开连接的时候发送disconnected()信号，触发slotDisconnected()槽函数
void Dialog::slotDisconnected()
{
    sendBtn->setEnabled(false);
    enterBtn->setText(tr("进入聊天室"));
}
void Dialog::dataReceived()
{
    //循环条件是等待读取的字节数大于0，也就是说还有数据没有读出来
    while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray datagram;
        //统一长度
        datagram.resize(tcpSocket->bytesAvailable());
        //开始读取有效数据
        tcpSocket->read(datagram.data(),datagram.size());
        //把读取到的数据转化为QString类型
        QString msg=datagram.data();
        contentListWidget->addItem(msg.left(datagram.size()));
    }
}
