#include "Widget.h"

#include <QApplication>

/*
QT编辑器快捷键
注释  CTRL+/
运行  CTRL+r
构建  CTRL+b
转到定义/声明切换 F2
返回  LALT + ←
前进  LALT + →
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //定义应用程序对象
    Widget w;
    //定义空窗口对象
    w.show();
    //调用空窗口的子函数，显示窗口
    return a.exec();
    //调用应用程序对象 消息循环函数
}
