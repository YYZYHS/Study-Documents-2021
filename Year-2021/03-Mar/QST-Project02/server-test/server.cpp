#include "server.h"
#include <string.h>

Server::Server()
{

}

Server::Server(int port)
{
    listen(QHostAddress::Any,port);
}

void Server::incomingConnection(qintptr handle)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(handle);
    connect(socket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
}

void Server::receiveMessage()
{
    QByteArray arr = socket->readAll();
    QString str = arr.data();
}

void Server::sendMessage()
{
    QString str =a.toUtf8();
    socket->write(str.toUtf8());
}

