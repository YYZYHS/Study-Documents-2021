
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
	pid=fork();  //创建进程
	if(pid<0)
		perror("fork");
	if(pid==0)
	{
		while(1)
		{
			printf("this is son process\n");
			sleep(1);
		}
	}
	else 
	{
		while(1)
		{
			printf("this is father process\n");
			sleep(1);
		}
	}
	return 0;
}




