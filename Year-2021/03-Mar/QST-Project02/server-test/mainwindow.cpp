#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(sendm()),server,SLOT(sendMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    int port = ui->lineEdit->text().toInt();
    server = new Server(port);
}

void MainWindow::on_pushButton_4_clicked()
{
}

void MainWindow::on_pushButton_clicked()
{
    server->a = ui->command->text().toUtf8();
    emit sendm();
}
