#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include "register.h"
#include <QMovie>
int index=1;
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
//    QMovie *movie = new QMovie("://img/im.gif");
//    ui->imgif->setMovie(movie);
//    movie->start();

    ui->imgif->setPixmap(QPixmap("://img/bj233.png"));
    ui->label_3->setAttribute(Qt::WA_TranslucentBackground);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    query = new QSqlQuery;
    bool ok = query->exec("select *from  user");
    if(!ok)
    {
        QMessageBox::information(this,("提示"),("当前没有用户"));
    }
    else
    {
        while(query->next())
        {
            QString sname=query->value("username").toString();
            QString spass=query->value("passwd").toString();
            QString uname = ui->user->text();
            QString upass = ui->pass->text();
            if(sname==uname&&spass==upass)
            {
                this->hide();
                w = new Widget(0,sname);
                w->show();
                index=0;
                break;
            }
        }
        if(index!=0)
        {
            QMessageBox::information(this,("提示"),("用户名或密码错误"));

        }

    }
}

void Login::on_zhuce_clicked()
{
    qDebug()<<"q";
    Register *r = new Register();
    this->hide();
    r->show();
}

void Login::on_user_textChanged(const QString &arg1)
{
    QString username = ui->user->text();
    query = new QSqlQuery;
    bool ok = query->exec("select *from  user");
    while(query->next())
    {
        QString sname=query->value("username").toString();
        QString simg=query->value("imgname").toString();
        if(sname==username)
        {
            QString s = "border-image: url("+simg+")";
            ui->img->setStyleSheet(s);
            break;
        }
    }

}
