#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/Image/Image/background3.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    connect(&login,SIGNAL(openemulator()),this,SLOT(OpenEmulator()));
    connect(&e,SIGNAL(mainwindowclose()),this,SLOT(close()));
    connect(this,SIGNAL(led_on()),&e,SLOT(LED_on()));
    connect(this,SIGNAL(led_off()),&e,SLOT(LED_off()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    login.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Register reg;
    reg.exec();
}

void MainWindow::OpenEmulator()
{
    qDebug()<<"e";
    e.show();
    qDebug()<<"e";
}

void MainWindow::on_toolButton_clicked(bool checked)
{
    if(checked == 0)
    {
        //关灯
        qDebug()<<"check == 0";
        emit led_off();
    }
    else
    {
        //开灯
        qDebug()<<"check == 1";
        emit led_on();
    }
}

void MainWindow::on_pushButton_4_clicked(bool checked)
{
    if(checked == 0)
    {
        //关闭警报
        buzzer->stop();

    }
    else
    {
        //打开警报
        buzzer->setLoops(100);
        buzzer->play();

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->Feedback->setText(e.GetTemperature());
}
