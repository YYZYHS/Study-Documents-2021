#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QDebug>


class Button:public QPushButton
{
public:
    Button();
    Button(QWidget *p,QString name)
    {
        setParent(p);
        setText(name);
    };
    ~Button()
    {
        qDebug()<<"自制按钮对象已被释放";
    };
};

#endif // BUTTON_H
