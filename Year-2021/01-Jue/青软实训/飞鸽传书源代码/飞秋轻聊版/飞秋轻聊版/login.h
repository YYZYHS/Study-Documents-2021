#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QSqlQuery>
#include "widget.h"
#include <QMouseEvent>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QSqlQuery *query;
    Widget *w;
private slots:
    void on_pushButton_clicked();
    void on_zhuce_clicked();

    void on_user_textChanged(const QString &arg1);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
