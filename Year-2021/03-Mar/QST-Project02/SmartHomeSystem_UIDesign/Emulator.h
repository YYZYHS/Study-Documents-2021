#ifndef EMULATOR_H
#define EMULATOR_H

#include <QDialog>
#include <QtMultimedia/QSound>
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

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

signals:
    void mainwindowclose();

private:
    Ui::Emulator *ui;
};

#endif // EMULATOR_H
