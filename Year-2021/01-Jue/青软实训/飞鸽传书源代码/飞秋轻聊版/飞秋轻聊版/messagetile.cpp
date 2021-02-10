#include "titlewidget.h"
#include "messagetile.h"
#include <QVBoxLayout>
#include "mypushbutton.h"
#include <QLabel>
#include <QPainter>
#include <QBitmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QDesktopServices>
QTimer *timerShow;
QTimer *timerStay;
QTimer *timerClose;
QPoint normalPoint;
QRect deskRect;
titlewidget *titleW;
mypushbutton *btnLook;
MessageTile::MessageTile(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    isEnter = false;
    titleW=new titlewidget;
    connect(titleW,SIGNAL(myClose()),this,SLOT(close()));
    content=new QLabel;
    content->setWordWrap(true);
    content->setAlignment(Qt::AlignTop);
    content->setFixedSize(300,100);
    btnLook=new mypushbutton("look.png","查看",0);
    connect(btnLook,SIGNAL(clicked()),this,SLOT(seeInfo()));
    QVBoxLayout*mainLayout=new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->addWidget(titleW);
    mainLayout->addWidget(content);
    content->setMargin(5);
    mainLayout->addWidget(btnLook,0,Qt::AlignRight);
    setLayout(mainLayout);
    setFixedSize(sizeHint().width(),sizeHint().height());
    timerShow=new QTimer(this);
    connect(timerShow,SIGNAL(timeout()),this,SLOT(myMove()));
    timerStay=new QTimer(this);
    connect(timerStay,SIGNAL(timeout()),this,SLOT(myStay()));
    timerClose=new QTimer(this);
    connect(timerClose,SIGNAL(timeout()),this,SLOT(myClose()));
}
MessageTile::~MessageTile()
{

}
void MessageTile::setMsg(QString title, QString content, QString work)
{
    titleW->setTitleText("  "+title);
    this->content->setText("   "+content);
}
void MessageTile::paintEvent(QPaintEvent *)
{

    QBitmap bitmap(this->size());
    bitmap.fill(Qt::white);
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(250,240,230)));
    painter.setPen(QPen(QBrush(QColor(255,222,173)),4));
    painter.drawRoundedRect(bitmap.rect(),5,5);
    setMask(bitmap);
}

void MessageTile::showAsQQ()
{
    QDesktopWidget *deskTop=QApplication::desktop();
    deskRect=deskTop->availableGeometry();
    normalPoint.setX(deskRect.width()-rect().width()-1);
    normalPoint.setY(deskRect.height()-rect().height());
    move(normalPoint.x(),deskRect.height()-1);
    show();
    timerShow->start(5);

}

//平滑显示出来

void MessageTile::myMove()
{
    static int beginY=QApplication::desktop()->height();
    beginY--;
    move(normalPoint.x(),beginY);
    if(beginY<=normalPoint.y())
    {
        timerShow->stop();
        timerStay->start(1000);
    }

}

//停留显示

void MessageTile::myStay()
{
    static int timeCount=0;
    timeCount++;
    if(timeCount>=2)
    {
        timerStay->stop();
        timerClose->start(200);
    }
}

//自动关闭时实现淡出效果
void MessageTile::myClose()
{
   static double tran=1.0;
    if(isEnter){
        tran = 1.0;
        setWindowOpacity(tran);
        return;
    }
    tran-=0.1;
    if(tran<=0.0)
    {
       timerClose->stop();
        emit close();
    }
    else
        setWindowOpacity(tran);

}
void MessageTile::seeInfo()
{

}
void MessageTile::enterEvent(QEvent *)
{
    isEnter = true;
}

void MessageTile::leaveEvent(QEvent *)
{
    isEnter = false;
}
