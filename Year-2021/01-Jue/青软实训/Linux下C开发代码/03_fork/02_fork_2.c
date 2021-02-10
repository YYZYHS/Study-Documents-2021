#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var=10;    //全局变量     

int main(int argc, char *argv[])
{
	pid_t pid;
	int num=9;
	pid=fork();
	if(pid<0)
	{
		perror("fork");
	}
	if(pid==0)
	{
		var++;
		num++;
		printf("in son process var=%d,num=%d\n", var, num);
		sleep(2);
	}
	else
	{
		//sleep(1);  //等待一下子进程运行
		printf("in father process var=%d,num=%d\n", var, num);
		wait();//??
	}
	printf("common code area\n");
	return 0;
}



