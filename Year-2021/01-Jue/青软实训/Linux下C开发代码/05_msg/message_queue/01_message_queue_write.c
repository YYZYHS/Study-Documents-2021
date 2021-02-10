#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

//定义消息队列的消息结构体
typedef struct _msg
{
	long mtype; //消息类型
	char mtext[50];//消息正文
}MSG;

int main(int argc, char *argv[])
{
	key_t key;  //IPC键值
	int  msgqid;
	MSG msg;
	
	key = ftok(".", 2012); //获取key键值
	msgqid = msgget(key, IPC_CREAT|0666); //创建消息队列
	if (msgqid == -1)
	{
		perror("msgget");
		exit(-1);
	}
	msg.mtype = 10;  //消息队列的消息结构体赋值操作
	strcpy(msg.mtext, "hello world");
	msgsnd(msgqid, &msg, sizeof(msg.mtext), 0);
	return 0;
}

