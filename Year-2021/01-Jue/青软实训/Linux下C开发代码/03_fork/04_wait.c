
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
	pid=fork();
	if(pid<0)
		perror("fork");
	if(pid==0)
	{
		int i = 0;
		for(i=0;i<5;i++)
		{
			printf("this is son process\n");
			sleep(1);
		}
		_exit(2);
	}
	else 
	{
		int status = 0;
		
		wait(&status);
		if(WIFEXITED(status)!=0)
		{
			printf("son process return %d\n", WEXITSTATUS(status));
		}
		printf("this is father process\n");	
	}
	return 0;
}

