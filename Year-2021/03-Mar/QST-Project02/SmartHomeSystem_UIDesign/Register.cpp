#include "Register.h"
#include "ui_Register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_buttonBox_2_accepted()
{
    qDebug()<<"OK";
    this->close();
}

void Register::on_buttonBox_2_rejected()
{
    qDebug()<<"Cancle";
    this->close();
}
