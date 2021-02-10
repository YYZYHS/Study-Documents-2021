#include "brow.h"
#include "ui_brow.h"
#include <QDebug>
#include <QLabel>
#include <QMovie>
QLabel *l;
QMovie *movie;
Brow::Brow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Brow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true);
//    QLabel *l = new QLabel(this);
//    l->setGeometry(0,0,30,30);
//    QMovie *movie = new QMovie("://qqexpression/11.gif");
//    l->setMovie(movie);
//    movie->start();

}

Brow::~Brow()
{
    delete ui;
}

void Brow::paintEvent(QPaintEvent *)
{
    int m;
    QPainter s(this);
    int n=30;
    for(int i = 0;i<9;i++)
        for(int j= 0;j<9;j++)
        {
            if(i==0)
                m = i*10+j+1;
            else
                m = i*10+j;
            s.drawPixmap(n*j,n*i,n,n,QPixmap(QString("://qqexpression/%1.gif").arg(m)));
        }
    int x = kx/30*30;
    int y = ky/30*30;
    s.drawRect(x,y,30,30);
    update();
}

void Brow::mousePressEvent(QMouseEvent *)
{
    int y = ky/30;
    int x;
    if(y==0)
    {
        x = kx/30+y*9+y+1;
    }else
    {
       x = kx/30+y*9+y;
    }
    imgPath = QString("://qqexpression/%1.gif").arg(x);
    mousepress();
}

void Brow::mouseMoveEvent(QMouseEvent *p)
{
    ky = p->y();
    kx = p->x();

}
