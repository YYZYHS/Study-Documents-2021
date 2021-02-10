#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//==========================================================================
// 语法格式：	int main(int argc, char *argv[])
// 实现功能：	主函数，建立一个UDP_echo_client
// 入口参数：	可以传参改变服务器的ip地址和其端口号，亦可不传参使用默认值
// 出口参数：	无
//==========================================================================

int main(int argc, char *argv[])
{
	int sockfd = 0;
	struct sockaddr_in dest_addr;
	unsigned short port = 8000;
	char *server_ip = "172.20.223.151";
	
	if( argc > 1 )													//服务器ip地址
	{		
		server_ip = argv[1];
	}	
	
	if( argc > 2 )													//服务器端口
	{
		port = atoi(argv[2]);
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);     //创建UDP套接字
	if(sockfd < 0)
	{
		perror("socket error!");
		exit(-1);
	}
	
	bzero(&dest_addr, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port   = htons(port);
	inet_pton(AF_INET, server_ip, &dest_addr.sin_addr);

	printf("ready send data to UDP server %s:%d!\n", server_ip, port);
	
	while(1)
	{
		char send_buf[512] = "";
		char recv_buf[512] = "";
		
		fgets(send_buf, sizeof(send_buf), stdin);   //获取输入
		send_buf[strlen(send_buf)-1] = '\0';
		
		sendto(sockfd, send_buf, strlen(send_buf), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));  //发送数据
		
		recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, NULL, NULL);	   //接收数据，并且不关心数据来源	
		printf("%s\n", recv_buf);
	}
	
	close(sockfd);
	return 0;
}
