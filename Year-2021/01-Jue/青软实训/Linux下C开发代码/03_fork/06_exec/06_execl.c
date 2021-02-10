
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	execl("/bin/ls", "ls", "-a", "-l", "-h", NULL);
		perror("execl");
	return 0;
}


