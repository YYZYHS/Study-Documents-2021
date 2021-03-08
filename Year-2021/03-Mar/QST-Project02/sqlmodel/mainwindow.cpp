#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

//message m = {0,0,0,0,0,"127.0.0.1",5005};理由：message已内置

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!createConnection())
        qDebug()<<QObject::tr("数据库操作失败！\n");
    model = new QSqlTableModel(this);
    model->setTable("desktop");
    model->select();

    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 开灯按钮
void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"开灯槽触发";
    QTcpSocket * temp=server->getsocket();
    QString str = "00";
    temp->write(str.toUtf8());
    qDebug()<<"开灯槽退出";
}

// 关灯按钮
void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"关灯槽触发";
    QTcpSocket * temp=server->getsocket();
    QString str = "01";
    temp->write(str.toUtf8());
    qDebug()<<"关灯槽退出";
}

// 显示全表按钮
void MainWindow::on_pushButton_6_clicked()
{
    qDebug()<<"全表显示被触发";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from desktop");
    model->setHeaderData(0, Qt::Horizontal, tr("IP"));
    model->setHeaderData(1, Qt::Horizontal, tr("Port"));

    ui->tableView->setModel(model);
    ui->tableView->show();
    qDebug()<<"全表显示退出";
}

// 传回温度
void MainWindow::on_pushButton_7_clicked()
{
    qDebug()<<"温度槽触发";
    QTcpSocket * temp=server->getsocket();
    QString str = "20";
    temp->write(str.toUtf8());
    qDebug()<<"温度槽退出";
}

// 清空
void MainWindow::on_pushButton_8_clicked()
{
    qDebug()<<"清空槽被触发";
    QSqlQuery query(db);
    bool ok=query.exec("DROP TABLE Buff");
    if(ok)
        qDebug()<<"数据库清空失败";
    qDebug()<<"清空槽退出";
}
// 关闭蜂鸣器
void MainWindow::on_pushButton_4_clicked()
{
    qDebug()<<"关喇叭槽触发";
    QTcpSocket * temp=server->getsocket();
    QString str = "11";
    temp->write(str.toUtf8());
    qDebug()<<"关喇叭槽退出";
}
// 打开蜂鸣器
void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<<"开喇叭槽触发";
    QTcpSocket * temp=server->getsocket();
    QString str = "10";
    temp->write(str.toUtf8());
    qDebug()<<"开喇叭槽退出";
}
//创建端口
void MainWindow::on_pushButton_5_clicked()
{
    int port=ui->lineEdit->text().toInt();
    qDebug()<<"port:"<<port;
    server=new Server(port);
    connect(server,SIGNAL(arrive()),this, SLOT(set()));
}

void MainWindow::set()
{
    ui->label->setText(server->getstring());
}

void MainWindow::chitem(message)//修改表格
{

}

bool MainWindow::createConnection()//建立数据库
{
    qDebug()<<"建立数据库连接\n";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    db.open();
    last=new QSqlQuery();
    last->exec("create table desktop (IP varchar , Port int)");
    qDebug()<<"建表\n";
    last->exec("insert into desktop(IP,Port) values('127.0.0.1','6006')");
    qDebug()<<"插入\n";
    qDebug()<<"数据库建立完成\n";
    return true;
}
