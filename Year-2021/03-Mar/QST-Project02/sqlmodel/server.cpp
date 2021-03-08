#include "server.h"


Server::Server(int port)
{
    qDebug()<<"开始构建Server对象";
    listen(QHostAddress::Any,port);
    qDebug()<<"监听完成";
    qDebug()<<"等待连接";
}

void Server::incomingConnection(qintptr handle)
{
    qDebug()<<"C端进入连接";
    socket=new QTcpSocket(this);
    socket->setSocketDescriptor(handle);
//    qDebug()<<"C端完成连接";
//    qDebug()<<"开始转移C端IP和Port";

//    emit adddb();//发出注册信号
//    qDebug()<<"发送注册信号";
    connect(socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
}

QTcpSocket* Server::getsocket()
{
    return socket;
}

QString Server::getstring()
{
    return q;
}

void Server::recvMessage()
{
    QByteArray arr = socket->readAll();
    q = arr.data();
    emit arrive();
}
