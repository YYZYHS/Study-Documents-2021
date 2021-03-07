#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "Login.h"
#include "ui_Login.h"
#include "Emulator.h"
#include "ui_Emulator.h"
#include <QtMultimedia/QSound>
#include "Message.h"
#include "Transfer.h"


#include <QtNetwork>
#include <QAbstractSocket>



class Login;
class Emulator;
class Transfer;

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
    Login login;
    QTcpSocket *socket;
    Transfer t;
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void OpenEmulator();

    void on_toolButton_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_3_clicked();

    void Upload();

    void Receivemessage();

    void Sendmessage(MessageType type,message m);

    void ChangeBeepBtntrue();
    void ChangeBeepBtnfalse();

    void getInfo();

    void on_pushButton_6_clicked();

    void ChangeInfo();

    void ChangeLedBtnfalse();

signals:
    void led_on();
    void led_off();
    void beep_on();
    void beep_off();
    void getstatus();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
