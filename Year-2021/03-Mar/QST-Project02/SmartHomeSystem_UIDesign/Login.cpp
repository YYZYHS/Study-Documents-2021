#include "Login.h"
#include "ui_Login.h"
#include <QDebug>

message m = {1,1,0,0,0,"127.0.0.1",5005};

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{ 
    m.IPAddr = ui->ServerIP->text();
    m.port = ui->PortID->text().toInt();
    emit upload();
    qDebug()<<"OK";
    usrname = ui->UsrName->text();
    serverip = ui->ServerIP->text();
    emit openemulator();
    emit changeInfo();
    qDebug()<<"OK";
    this->hide();
    qDebug()<<"OK";
}

void Login::on_buttonBox_rejected()
{
    qDebug()<<"Cancle";
    this->close();
}
