#ifndef REGISTER_H
#define REGISTER_H
#include <QPaintEvent>
#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    void initImg();
    QString imgPath;
    int imgindex;
    void paintEvent(QPaintEvent *);
private slots:
    void on_returnbtn_clicked();

    void on_regbtn_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_passwd1_textChanged(const QString &arg1);

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
