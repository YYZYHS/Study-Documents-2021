
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *arg[]={"test", NULL};
	char *env[]={"USER=ME", "GONGSI=AIPU", NULL};
				
	execve("./test", arg, env);	
		perror("execve");
	return 0;
}

