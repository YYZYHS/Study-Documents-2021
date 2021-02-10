#include "server.h"

Server::Server(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);//在指定的端口对任意地址进行监听
}
void Server::incomingConnection(int socketDescriptor)
{
    //创建一个新的TcpClientSocket与客户端通信
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);
    //连接TcpClientSOcket的信号
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),
    this,SLOT(updateClients(QString,int))); //(b)
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,
    SLOT(slotDisconnected(int))); //(c)
    //将新创建的套接字的描述符指定为传入的socketDescriptor
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    //将套接字加入套接字列表
    tcpClientSocketList.append(tcpClientSocket); //(e)
}
void Server::updateClients(QString msg,int length)
{
    //发送信号，更新服务端窗口信息
    emit updateServer(msg,length); //(a)
    //向套接字列表中的每一项发送广播
    for(int i=0;i<tcpClientSocketList.count();i++) //(b)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}
void Server::slotDisconnected(int descriptor)
{
    //从列表中删除传入的标识符所代表的套接字（这个函数的作用是删除列表中已断开连接的套接字）
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
        tcpClientSocketList.removeAt(i);
        return;
        }
    }
    return;
}
