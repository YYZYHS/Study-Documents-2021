#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTcpServer>
#include "tcpserver.h"
#include "tcpclient.h"
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextCharFormat>
namespace Ui {
class Widget;
}
enum MessageType{Message, NewParticipant,
                 ParticipantLeft, FileName, Refuse};

class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = 0,QString sname="");
    ~Widget();
protected:
    void newParticipant(QString userName,
                        QString localHostName,
                        QString ipAddress,
                        QString sname);
    void participantLeft(QString userName,
                         QString localHostName,
                         QString time,
                         QString sname);
    void sendMessage(MessageType type,
                     QString serverAddress="");
    void hasPendingFile(QString userName, QString serverAddress,
                            QString clientAddress, QString fileName);
    //void closeEvent(QCloseEvent *);
    QString getIP();
    QString getUserName();
    QString getMessage();
    QString getImg(QString username);
    void stringToHtmlFilter(QString &str);
    void stringToHtml(QString &str,QColor crl);
    void imgPathToHtml(QString &path);
private slots:
    void processPendingDatagrams();
    void getFileName(QString);
    void on_pushButton_clicked();
    void on_sendfile_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_messageTextEdit_currentCharFormatChanged(const QTextCharFormat &format);
    void on_pushButton_5_clicked();

    void on_messageTextEdit_selectionChanged();

signals:
    void sendFileName(QString);
private slots:
    void imginsert();
private:
    Ui::Widget *ui;
    QString fileName;
    QUdpSocket *udpSocket;
    TcpServer *server;
    qint16 port;
    QString sname;
};

#endif // WIDGET_H
