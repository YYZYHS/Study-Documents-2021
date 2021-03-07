#ifndef EMULATOR_H
#define EMULATOR_H

#include <QDialog>
#include <QtMultimedia/QSound>
#include <QMouseEvent>
#include "Login.h"
namespace Ui {
class Emulator;
}

class Emulator : public QDialog
{
    Q_OBJECT

public:
    explicit Emulator(QDialog *parent = nullptr);
    ~Emulator();
    QString GetTemperature();
    QSound *buzzer = new QSound(":/music/music/buzzer.wav");

private slots:
    void on_pushButton_3_clicked();
    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void LED_on();
    void LED_off();
    void Beep_off();
    void Beep_on();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked(bool checked);

signals:
    void mainwindowclose();
    void MainwindowBeepOn();
    void MainWindowBeepOff();
    void getstatus();
    void settempzero();
    void MainWindowLedOff();

private:
    Ui::Emulator *ui;
    QPoint offset;//鼠标与窗口相对位置的差值
    bool a;
protected:
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
};

#endif // EMULATOR_H
