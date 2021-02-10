
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int status;
	
	status = system("ls -alh");
	if(WIFEXITED(status))
	{
		printf("the exit status is %d \n", status);
	}
	else
	{
		printf("abnornamal exit\n");
	}
	return 0;
}

