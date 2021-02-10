#include "widget.h"
#include <QApplication>
#include "login.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include "brow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        //qDebug()<<db.lastError();
    }else
    {
        qDebug()<<"success";
        qDebug()<<db.tables();
        qDebug()<<QSqlDatabase::drivers();
    }
    Login l;
    l.show();
//    Brow b;
//    b.show();
    return a.exec();
}
