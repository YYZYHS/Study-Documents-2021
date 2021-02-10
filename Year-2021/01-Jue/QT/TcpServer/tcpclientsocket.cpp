#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    //当接收到数据报的时候，发出信号readyRead()

    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    //(b)
}

void TcpClientSocket::dataReceived()
{
    while(bytesAvailable()>0)
    {
        //保存有效数据的长度
        int length = bytesAvailable();
        char buf[1024];
        //写入到buf中，并转换成QString类型
        read(buf,length);
        QString msg=buf;
        //发送信号，向客户端广播消息
        emit updateClients(msg,length);
    }
}
void TcpClientSocket::slotDisconnected()
{
    //socketDescriptor()的返回值是socket的描述符，如果没有连接则返回-1
    emit disconnected(this->socketDescriptor());
}
