#include "Widget.h"
#include <QPushButton>
#include "button.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Hello QT");   //设置窗口标题
    this->resize(400,800);              //设置窗口大小
    //this->setFixedSize(200,200);        //固定窗口大小


    //创建按钮
    QPushButton* btn = new QPushButton;
    btn->resize(300,50);//设置大小
    btn->setParent(this);//设置父亲，有了这句，可以不需要手动释放了
    btn->setText("开始游戏");//设置文本
    QFont font("华文新魏",20,10,1);//创建字体对象(字体，大小，加粗，倾斜)
    btn->setFont(font);//设置字体
    btn->move(100,100);//设置按钮位置
    btn->show();//显示按钮，放在最后
    //了解 ---> Qt支持CS4语法
    btn->setStyleSheet("QPushButton{ background-color:red;}\
                        QPushButton:hover{ background-color:green;}\
                        QPushButton:pressed{ background-color:rgba(100,155,113,1);}");

    ////////////这里是自制类////////////

    ////////////这里是自制按钮类////////////
    Button *btn1 = new Button;
    btn1->setText("不带参数自制按钮类对象");
    btn1->setParent(this);
    btn1->move(100,0);
    Button *btn2 = new Button(this,"带参数自制按钮类对象");
    btn2->move(200,0);
    btn1->show();
    btn2->show();

    //做个对比
    QPushButton *btn3 = new QPushButton("Qt自带单参数按钮类对象",this);
    btn3->move(0,500);
    btn3->show();


    ////////////这里是自制普通类////////////


//   Student *stu = new Student;
//   //现在是不能释放stu对象的
//   Student *stu1 = new Student;
//   stu1->setParent(this);
//   //设置父亲为本窗口，当本窗口释放时，会先释放子对象
//   //建立好了对象树，现在可以自动释放了



}

Widget::~Widget()
{
}

