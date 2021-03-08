#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    Server(int port);
    void incomingConnection(qintptr handle);
    QTcpSocket *socket;
    QString a;

private slots:
    void receiveMessage();
    void sendMessage();
};

#endif // SERVER_H
