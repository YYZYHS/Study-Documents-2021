#ifndef EMULATOR_H
#define EMULATOR_H

#include <QDialog>

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

private slots:
    void on_pushButton_3_clicked();
    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void LED_on();
    void LED_off();

signals:
    void mainwindowclose();

private:
    Ui::Emulator *ui;
};

#endif // EMULATOR_H
