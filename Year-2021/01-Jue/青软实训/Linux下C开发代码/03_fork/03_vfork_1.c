
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	pid_t pid;
	
	pid = vfork();
	if(pid<0)
		perror("vfork");
	if(pid==0)
	{
		int i = 0;
		for(i=0;i<5;i++)
		{
			printf("this is son process\n");
			sleep(1);
		}
		_exit(0);
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
