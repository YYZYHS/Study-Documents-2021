
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *arg[]={"ls", "-a", "-l", "-h", NULL};
	
	execv("/bin/ls", arg);
		perror("execv");
	return 0;
}

