#ifndef BROW_H
#define BROW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
namespace Ui {
class Brow;
}

class Brow : public QWidget
{
    Q_OBJECT

public:
    explicit Brow(QWidget *parent = 0);
    ~Brow();
    QString imgPath;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    int kx;
    int ky;
signals:
    void mousepress();

private:
    Ui::Brow *ui;
};

#endif // BROW_H
