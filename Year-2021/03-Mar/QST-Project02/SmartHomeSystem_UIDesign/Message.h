#ifndef MESSAGE_H
#define MESSAGE_H


#include <QString>
#include <QDebug>

enum MessageType{sendCommand,getCommend,GetStatus};//注册，登录，指令，获取板子状态
//enum ComObject{LED,Beep,TEMP};
typedef struct dbitem
{
    char* IPAddr;//记录IP地址

}dbitem;
typedef struct message
{
    int ledstatu;//led状态
    int beepstatu;//蜂鸣器状态
    int temp;//温度值
    int CO;//指令对象
    //0---led,1---beep,2---temp
    int command;//指令值
    QString IPAddr;//IP地址
    int port;//端口
}message;



#endif // MESSAGETYPES_H
