#ifndef EMULATOR_H
#define EMULATOR_H

#include <QDialog>
#include <QtMultimedia/QSound>
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

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

signals:
    void mainwindowclose();
    void MainwindowBeepOn();
    void MainWindowBeepOff();
    void getstatus();
    void settempzero();
    void MainWindowLedOff();

private:
    Ui::Emulator *ui;
};

#endif // EMULATOR_H
