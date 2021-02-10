#include "mypushbutton.h"
#include <QPalette>
#include <QPixmap>
#include <QCursor>
#include <QPushButton>
#include <QMouseEvent>
mypushbutton::mypushbutton(QWidget *parent) :
    QPushButton(parent)
{
}
mypushbutton::mypushbutton(QString iconStr,QString textStr, QWidget *parent):QPushButton(parent)
{
    QPixmap pixmap(":/Resources/"+iconStr);
    setIcon(QIcon(pixmap));
    setIconSize(pixmap.size());
    setText(textStr);
    resize(pixmap.size());
    setBkPalette(0);//设置背景完全透明
    setFlat(true);
    setAutoFillBackground(true);
}

void mypushbutton::setBkPalette(int transparency)//设置背景透明度
{
   QPalette palette;
   palette.setBrush(QPalette::Button,QBrush(QColor(255,255,255,transparency)));
   setPalette(palette);
}
void mypushbutton::enterEvent(QEvent *)
{
    setCursor(Qt::PointingHandCursor);
}
void mypushbutton::leaveEvent(QEvent *)
{
    setCursor(Qt::CustomCursor);
}
void mypushbutton::mousePressEvent(QMouseEvent *e)
{

}
void mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{

    emit clicked();
}
