#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPixmap back(":/Image/Image/back.jpg");
//    back = back.scaled(800,80,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
//    ui->pic_Welcome->setPixmap(back);
    QPixmap pixmap = QPixmap(":/Image/Image/background3.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
