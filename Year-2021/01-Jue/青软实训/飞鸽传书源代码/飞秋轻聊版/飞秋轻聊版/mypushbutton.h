#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mypushbutton(QWidget *parent = 0);
    explicit mypushbutton(QString iconStr,QString textStr, QWidget *parent);
    void setBkPalette(int transparency);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:


public slots:

};

#endif // MYPUSHBUTTON_H
