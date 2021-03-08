#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include "transfer.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(int port);
    void incomingConnection(qintptr handle);
    QTcpSocket* getsocket();
    QString getstring();
private:
    QTcpSocket *socket;
    QString q;
private slots:
    void recvMessage();
signals:
    void arrive();
    void adddb();//注册信号
};

#endif // SERVER_H
