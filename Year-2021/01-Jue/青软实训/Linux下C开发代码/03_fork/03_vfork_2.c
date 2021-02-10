#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 10;
int main(int argc, char *argv[])
{
	pid_t pid;
	int num = 9;

	pid = vfork();
	if(pid<0)
	{
		perror("vfork");
	}
	if(pid == 0)
	{
		var++;
		num++;
		printf("in son process var=%d,num=%d\n", var, num);
		_exit(0);
	}
	else
	{
		printf("in father process var=%d,num=%d\n", var, num);
	}
	return 0;
}
