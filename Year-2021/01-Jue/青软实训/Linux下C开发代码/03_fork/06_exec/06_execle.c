
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *env[]={"USER=ME", "GONGSI=AIPU", NULL};
	
	execle("./test", "test", NULL, env);
		perror("execle");
	return 0;
}

