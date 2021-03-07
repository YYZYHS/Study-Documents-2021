#include "Login.h"
#include "ui_Login.h"
#include <QDebug>

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
    qDebug()<<"OK";
    emit openemulator();
    qDebug()<<"OK";
    this->close();
    qDebug()<<"OK";
}

void Login::on_buttonBox_rejected()
{
    qDebug()<<"Cancle";
    this->close();
}
