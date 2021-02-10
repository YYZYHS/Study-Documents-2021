#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>//包含Qt空窗口头文件
#include "Student.h"

class Widget : public QWidget
{
    Q_OBJECT//支持信号 和 槽

public:
    Widget(QWidget *parent = nullptr);//构造函数
    ~Widget();//析构函数
};
#endif // WIDGET_H
