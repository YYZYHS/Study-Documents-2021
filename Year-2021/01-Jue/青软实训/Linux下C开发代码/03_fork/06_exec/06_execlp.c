
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	execlp("ls", "ls", "-a", "-l", "-h", NULL);
		perror("execlp");
	return 0;
}


