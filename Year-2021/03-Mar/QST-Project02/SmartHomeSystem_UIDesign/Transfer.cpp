#include "Transfer.h"


Transfer::Transfer()
{

}

QByteArray Transfer::sendmessage(MessageType type,message m)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    switch (type)
    {
    case sendCommand:
    {
        out<<m.IPAddr<<m.CO<<m.command;//包含ip地址、命令对象、命令
        break;
    }
    case GetStatus:
    {
        out<<m.IPAddr<<m.ledstatu<<m.beepstatu<<m.temp;
        break;
    }

    default:qDebug()<<"error";
        break;
    }
    return data;
}

void Transfer::receivemessage(QByteArray data,message m)
{
    QDataStream in(&data,QIODevice::ReadOnly);
    int type;
    in>>type;
    switch (type)
    {
    case getCommend:
    {
        in>>m.IPAddr>>m.CO>>m.command;
        break;
    }
    case GetStatus:
    {
        in>>m.IPAddr>>m.ledstatu>>m.beepstatu>>m.temp;
        break;
    }
    default:qDebug()<<"error";
        break;
    }
}
