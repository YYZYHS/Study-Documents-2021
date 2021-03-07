#ifndef TRANSFER_H
#define TRANSFER_H
#include "Message.h"
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QNetworkInterface>
#include <QDataStream>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>


//enum MessageType{usrRegister,usrLogin,sendCommand,getCommend,GetStatus};//注册，登录，指令，获取板子状态
//typedef struct message
//{
//    int ledstatu;//led状态
//    int beepstatu;//蜂鸣器状态
//    int temp;//温度值
//    ComObject CO;//指令对象
//    int command;//指令值
//    QString IPAddr;//IP地址
//    int port;//端口
//}message;



class Transfer
{
public:
    Transfer();
    //编码
    QByteArray sendmessage(MessageType type,message m);
    //解码
    void receivemessage(QByteArray data,message m);

};

#endif // TRANSFER_H
