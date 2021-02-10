#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

class titlewidget : public QWidget
{
    Q_OBJECT
public:
    explicit titlewidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setTitleText(QString title);
signals:
    void myClose();
public slots:


};

#endif // TITLEWIDGET_H
