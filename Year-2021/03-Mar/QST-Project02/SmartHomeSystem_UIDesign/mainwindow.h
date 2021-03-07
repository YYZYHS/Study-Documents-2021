#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Login.h"
#include "ui_Login.h"
#include "Register.h"
#include "ui_Register.h"
#include "Emulator.h"
#include "ui_Emulator.h"
#include <QtMultimedia/QSound>

class Login;
class Register;
class Emulator;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSound *buzzer = new QSound(":/music/music/buzzer.wav");
    Emulator e;
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void OpenEmulator();

    void on_toolButton_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_3_clicked();

signals:
    void led_on();
    void led_off();

private:
    Ui::MainWindow *ui;
    Login login;

};

#endif // MAINWINDOW_H
