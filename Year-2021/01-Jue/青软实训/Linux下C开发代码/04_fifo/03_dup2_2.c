
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd1;
	int fd2 = 3;
	int err = 0;
	
	err = dup2(1,fd2);//save 1
	if(err<0)
	{
		perror("dup2");
	}
	printf("fd2=%d,err=%d\n", fd2, err);
	

	fd1 = open("test", O_CREAT|O_RDWR, S_IRWXU);
	dup2(fd1,1);    // dup2(fd1,1) = 1
	printf("hello world\n");

	dup2(fd2,1);//dup2(fd2,1)=1
	printf("I love you \n");
	return 0;
}




