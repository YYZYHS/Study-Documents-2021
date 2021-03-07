#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "Message.h"


extern message m;


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString usrname;
    QString serverip;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
signals:
    void openemulator();
    void upload();
    void changeInfo();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
