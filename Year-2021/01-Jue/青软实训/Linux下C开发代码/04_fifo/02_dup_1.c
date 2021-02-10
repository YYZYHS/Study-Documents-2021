
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd1;
	int fd2;
	
	fd1 = open("test", O_CREAT | O_WRONLY,0777);
	if (fd1 < 0)
	{
		perror("open");
		exit(-1);
	}
	close(1);
	fd2 = dup(fd1);
	printf("fd2=%d\n", fd2);
	return 0;
}


