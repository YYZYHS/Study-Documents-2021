#ifndef MESSAGETILE_H
#define MESSAGETILE_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class MessageTile;
}

class MessageTile : public QWidget
{
    Q_OBJECT

public:
    explicit MessageTile(QWidget *parent = 0);
    ~MessageTile();
    bool isEnter;
    QLabel *content;
    void showAsQQ();
    void setMsg(QString title, QString content, QString work);

private:
    Ui::MessageTile *ui;

    void paintEvent(QPaintEvent *);

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
private slots:
    void myMove();
    void myStay();
    void myClose();
    void seeInfo();
};

#endif
