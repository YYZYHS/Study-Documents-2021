#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
signals:
    void openemulator();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
