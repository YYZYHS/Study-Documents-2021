#include "Emulator.h"
#include "ui_Emulator.h"
#include <QDebug>

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
    qDebug()<<arg1;
    ui->horizontalSlider->setValue(ui->spinBox->value());
    m.temp = ui->spinBox->value();
}

void Emulator::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<value;
    ui->spinBox->setValue(ui->horizontalSlider->value());
    m.temp = ui->horizontalSlider->value();
}

void Emulator::on_pushButton_clicked()
{
//    int temperature = ui->spinBox->value();
//    //QString text ="当前温度："<<temperature<<"℃"；
//    QString text = QString("当前温度：%1℃").arg(temperature);
//    ui->label_3->setText(text);
    emit getstatus();
}

void Emulator::LED_on()
{
    //开灯
    QPixmap ledon = QPixmap(":/Image/Image/led-on.png");
    ui->LED->setPixmap(ledon);
    m.ledstatu = 0;
}

void Emulator::LED_off()
{
    //关灯
    QPixmap ledoff = QPixmap(":/Image/Image/led-off.png");
    ui->LED->setPixmap(ledoff);
    m.ledstatu = 1;

}

QString Emulator::GetTemperature()
{
    return ui->label_3->text();
}

void Emulator::on_pushButton_5_clicked()
{
    //开警报
    Beep_on();
    emit MainwindowBeepOn();

}

void Emulator::on_pushButton_6_clicked()
{
    //关警报
    Beep_off();
    emit MainWindowBeepOff();
}

void Emulator::on_pushButton_4_clicked()
{
    //模拟警报器

}

void Emulator::on_pushButton_7_clicked()
{
    //结束模拟

}
void Emulator::Beep_on()
{
    buzzer->setLoops(100);
    buzzer->play();
    m.beepstatu = 0;
}
void Emulator::Beep_off()
{
    buzzer->stop();
    m.beepstatu = 1;
}

void Emulator::on_pushButton_2_clicked()
{
    LED_off();
    Beep_off();
    ui->spinBox->setValue(0);
    ui->horizontalSlider->setValue(0);
    emit MainWindowBeepOff();
    emit MainWindowLedOff();

}
