#include "titlewidget.h"
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QLinearGradient>
#include <QIcon>
QLabel *titleText;
QToolButton *btnClose;
titlewidget::titlewidget(QWidget *parent) :
    QWidget(parent)
{
    titleText=new QLabel;
    btnClose = new QToolButton(this);
    btnClose->setObjectName(QString::fromUtf8("btnClose"));
    btnClose->setToolTip(tr("关闭"));
    btnClose->setStyleSheet(QString::fromUtf8("QWidget[objectName=\"btnClose\"]{\n"
        "border-width: 0px;\n"
        "border-style: solid;\n"
        "padding: 0px;\n"
        "padding-left: 0px;\n"
        "padding-right: 0px;\n"
        "min-width: 16px;\n"
        "max-width: 16px;\n"
        "min-height: 16px;\n"
        "max-height: 16px;\n"
        "background-image: url(:/Resources/btn_close_normal.bmp);\n"
        "}\n"
        "\n"
        "QWidget[objectName=\"btnClose\"]:hover{\n"
        "background-image: url(:/Resources/btn_close_highlight.bmp);\n"
        "}\n"
        "\n"
        "QWidget[objectName=\"btnClose\"]:pressed{\n"
        "background-image: url(:/Resources/btn_close_down.bmp);\n"
        "}\n"
        ""));
    connect(btnClose,SIGNAL(clicked()),this,SIGNAL(myClose()));
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(titleText,0,Qt::AlignLeft);
    layout->addStretch();
    layout->addWidget(btnClose,0,Qt::AlignRight);
    layout->setMargin(0);
    setLayout(layout);
    setFixedHeight(20);
}

void titlewidget::paintEvent(QPaintEvent *)
{
    QLinearGradient linear(rect().topLeft(),rect().bottomRight());
    linear.setColorAt(0,QColor(227,207,87));
    linear.setColorAt(0.5,QColor(245,222,179));
    linear.setColorAt(1,QColor(189,252,201));

    QPainter painter(this);
    painter.setBrush(QBrush(linear));
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}

void titlewidget::setTitleText(QString title)
{
    titleText->setText(title);
}
