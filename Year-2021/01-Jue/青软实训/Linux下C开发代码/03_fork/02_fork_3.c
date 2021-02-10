#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int length = 0;
	char buf[] = "a write to stdout\n";
	
	length = write(1, buf, strlen(buf)); //系统调用函数write，不带缓冲区
	if(length != strlen(buf))
	{
		printf("write error\n"); //标准IO库函数printf，带缓冲区的
	}
	printf("before fork\n");  //父进程里的，fork之后也被复制到子进程中
	pid=fork();
	if(pid<0)
	{
		perror("fork");
	}
	else if(pid==0)
	{
		printf("in son process\n");
	}
	else
	{
		sleep(1);
		printf("in father process\n");
	}
	return 0;
}


