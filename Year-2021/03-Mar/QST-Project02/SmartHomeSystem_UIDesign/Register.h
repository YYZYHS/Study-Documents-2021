#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();


private:
    Ui::Register *ui;
};

#endif // REGISTER_H
