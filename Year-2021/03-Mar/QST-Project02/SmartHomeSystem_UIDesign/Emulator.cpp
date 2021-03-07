#include "Emulator.h"
#include "ui_Emulator.h"

Emulator::Emulator(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Emulator)
{
    ui->setupUi(this);
}

Emulator::~Emulator()
{
    delete ui;
}

void Emulator::on_pushButton_3_clicked()
{
    emit mainwindowclose();
    this->close();
}

void Emulator::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(ui->spinBox->value());
}

void Emulator::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(ui->horizontalSlider->value());
}

void Emulator::on_pushButton_clicked()
{
    int temperature = ui->spinBox->value();
    //QString text ="当前温度："<<temperature<<"℃"；
    QString text = QString("当前温度：%1℃").arg(temperature);
    ui->label_3->setText(text);
}

void Emulator::LED_on()
{
    //开灯
    QPixmap ledon = QPixmap(":/Image/Image/led-on.png");
    ui->LED->setPixmap(ledon);
}

void Emulator::LED_off()
{
    QPixmap ledoff = QPixmap(":/Image/Image/led-off.png");
    ui->LED->setPixmap(ledoff);
    //关灯
}

QString Emulator::GetTemperature()
{
    return ui->label_3->text();
}
