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
    this->close();

}

void Login::on_buttonBox_rejected()
{
    qDebug()<<"Cancle";
    this->close();
}
