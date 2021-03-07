#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/Image/Image/background3.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    connect(&login,SIGNAL(openemulator()),this,SLOT(OpenEmulator()));
    connect(&e,SIGNAL(mainwindowclose()),this,SLOT(close()));
    connect(this,SIGNAL(led_on()),&e,SLOT(LED_on()));
    connect(this,SIGNAL(led_off()),&e,SLOT(LED_off()));
    connect(&login,SIGNAL(upload()),this,SLOT(Upload()));
    connect(this,SIGNAL(beep_off()),&e,SLOT(Beep_off()));
    connect(this,SIGNAL(beep_on()),&e,SLOT(Beep_on()));
    connect(&e,SIGNAL(MainwindowBeepOn()),this,SLOT(ChangeBeepBtntrue()));
    connect(&e,SIGNAL(MainWindowBeepOff()),this,SLOT(ChangeBeepBtnfalse()));
    connect(this,SIGNAL(getstatus()),this,SLOT(getInfo()));
    connect(&e,SIGNAL(getstatus()),this,SLOT(getInfo()));
    connect(&login,SIGNAL(changeInfo()),this,SLOT(ChangeInfo()));
    connect(&e,SIGNAL(MainWindowLedOff()),this,SLOT(ChangeLedBtnfalse()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    login.exec();
}


void MainWindow::OpenEmulator()
{
    qDebug()<<"e";
    e.show();
    qDebug()<<"e";
}

void MainWindow::on_toolButton_clicked(bool checked)
{
    if(checked == 0)
    {
        //关灯
        qDebug()<<"check == 0";
        emit led_off();
    }
    else
    {
        //开灯
        qDebug()<<"check == 1";
        emit led_on();
    }
}

void MainWindow::on_pushButton_4_clicked(bool checked)
{
    if(checked == 0)
    {
        //关闭警报
        emit beep_off();
    }
    else
    {
        //打开警报
        emit beep_on();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    emit getstatus();
}

void MainWindow::Upload()
{
    //创建socket
    //socket=IP地址+端口号
    socket = new QTcpSocket(this);
    //连接
    socket->connectToHost(m.IPAddr,m.port);
    //接收信息
    connect(socket,SIGNAL(readyRead()),this,SLOT(ReceiveMessage()));
}

void MainWindow::Receivemessage()
{
    QByteArray arr = socket->readAll();
    t.receivemessage(arr,m);
    switch (m.CO)
    {
    case 0:
    {
        //led灯控制
        if(!m.command)
        {
            //开灯
            emit led_on();
            ui->toolButton->setChecked(1);
        }
        else
        {
            //关灯
            emit led_off();
            ui->toolButton->setChecked(0);
        }
        break;

    }
    case 1:
    {
        if(!m.command)
        {
            //开警报器
            emit beep_on();
            ui->pushButton_4->setChecked(1);
        }
        else
        {
            //关警报器
            emit beep_off();
            ui->pushButton_4->setChecked(0);
        }
        //beep蜂鸣器控制
        break;

    }
    case 2:
    {
        emit getstatus();//temp温度计数值获取（设置为全部状态获取）
        Sendmessage(GetStatus,m);
        break;
    }

    }
}

void MainWindow::Sendmessage(MessageType type,message m)
{
    QByteArray temp=t.sendmessage(type,m);
    //socket->write(data,data.length());
    socket->write(temp);
    //socket->write(data.toUtf8().data(),strlen(data.toUtf8().data()));
}

void MainWindow::ChangeBeepBtntrue()
{
    ui->pushButton_4->setChecked(1);
}

void MainWindow::ChangeBeepBtnfalse()
{
    ui->pushButton_4->setChecked(0);
}

void MainWindow::getInfo()
{
    QString LED = "关",BEEP = "关";
    if(!m.ledstatu) LED = "开";
    if(!m.beepstatu) BEEP = "开";
    int TEMP = m.temp;
    QString text = QString("当前LED状态：%1\n蜂鸣器状态：%2\n温度计数值：%3℃").arg(LED).arg(BEEP).arg(TEMP);
    ui->Feedback->setText(text);
}

void MainWindow::on_pushButton_6_clicked()
{
    int com = ui->Commend->text().toInt();
    switch(com)
    {
    case 00:
    {
        emit led_on();
        ui->toolButton->setChecked(1);
        break;
    }
    case 01:
    {
        emit led_off();
        ui->toolButton->setChecked(0);
        break;
    }
    case 10:
    {
        emit beep_on();
        ui->pushButton_4->setChecked(1);
        break;
    }
    case 11:
    {
        emit beep_off();
        ui->pushButton_4->setChecked(0);
        break;
    }
    case 20:
    {
        emit getstatus();
        break;
    }
    default:qDebug()<<"error";
        break;
    }
}

void MainWindow::ChangeInfo()
{
    QString usrname = login.usrname;
    QString serverip = login.serverip;
    ui->label_5->setText(usrname);
    ui->label_6->setText(serverip);
    ui->label_7->setText(QNetworkInterface().allAddresses().at(1).toString());
}

void MainWindow::ChangeLedBtnfalse()
{
    ui->toolButton->setChecked(0);
}
