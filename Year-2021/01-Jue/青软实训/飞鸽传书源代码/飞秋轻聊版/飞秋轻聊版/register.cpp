#include "register.h"
#include "ui_register.h"
#include "login.h"
#include <QMessageBox>
#include <QPainter>
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    imgPath = "";
    initImg();
}

Register::~Register()
{
    delete ui;
}

void Register::initImg()
{
    ui->btn1->setStyleSheet("border-image: url(:/img/kkx.jpg)");
    ui->btn2->setStyleSheet("border-image: url(:/img/pkq.jpg)");
    ui->btn3->setStyleSheet("border-image: url(:/img/xgg01.jpg)");
    ui->btn4->setStyleSheet("border-image: url(:/img/xmm02.jpg)");
    ui->btn5->setStyleSheet("border-image: url(:/img/xgg03.jpg)");
    ui->btn6->setStyleSheet("border-image: url(:/img/xmm.jpg)");
}

void Register::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    p.setPen(pen);
    switch(imgindex)
    {
    case 1:
        p.drawRect(50,230,80,70);
        break;
    case 2:
        p.drawRect(200,230,80,70);
        break;
    case 3:
        p.drawRect(350,230,80,70);
        break;
    case 4:
        p.drawRect(50,310,80,70);
        break;
    case 5:
        p.drawRect(200,310,80,70);
        break;
    case 6:
        p.drawRect(350,310,80,70);
        break;


    }
    update();
}

void Register::on_returnbtn_clicked()
{
    this->hide();
    Login *l = new Login();
    l->show();

}

void Register::on_regbtn_clicked()
{
    QString username = ui->username->text();
    QString passwd = ui->passwd->text();
    QString passwd1 = ui->passwd1->text();
    if((username!="")&&(passwd!="")&&
            (passwd1!="")&&(imgPath!=""))
    {
        if(passwd!=passwd1)
        {
            ui->passwd1->setStyleSheet("color: rgb(255, 0, 0)");
            QMessageBox::warning(0, tr("错误"),
                           tr("两次密码输入不一致"), QMessageBox::Ok);
        }else if(passwd == passwd1)
        {
            QSqlQuery query;
            query.prepare("INSERT INTO user (username,passwd,imgname) "
                          "VALUES (?,?,?)");
            query.addBindValue(username);
            query.addBindValue(passwd);
            query.addBindValue(imgPath);
            query.exec();
            QMessageBox::warning(0, tr("提示"),
                           tr("注册成功"), QMessageBox::Ok);
            this->close();
            Login *l = new Login();
            l->show();

        }
    }else if(username=="")
    {
        QMessageBox::warning(0, tr("错误"),
                       tr("用户名不能为空"), QMessageBox::Ok);
    }else if(passwd=="")
    {
        QMessageBox::warning(0, tr("错误"),
                       tr("密码不能为空"), QMessageBox::Ok);
    }else if(imgPath=="")
    {
        QMessageBox::warning(0, tr("错误"),
                       tr("请选择图片"), QMessageBox::Ok);
    }
}

void Register::on_btn1_clicked()
{
    imgPath = ":/img/kkx.jpg";
    imgindex=1;
}

void Register::on_btn2_clicked()
{
    imgPath = ":/img/pkq.jpg";
    imgindex=2;

}

void Register::on_btn3_clicked()
{
    imgPath = ":/img/xgg01.jpg";
    imgindex=3;

}

void Register::on_btn4_clicked()
{
    imgPath = ":/img/xmm02.jpg";
    imgindex=4;

}

void Register::on_btn5_clicked()
{
    imgPath = ":/img/xgg03.jpg";
    imgindex=5;

}

void Register::on_btn6_clicked()
{
    imgPath = ":/img/xmm.jpg";
    imgindex=6;

}

void Register::on_passwd1_textChanged(const QString &arg1)
{
    ui->passwd1->setStyleSheet("color: rgb(0, 0, 0)");
}
