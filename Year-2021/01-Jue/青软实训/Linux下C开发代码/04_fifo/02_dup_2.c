
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd1;
	int fd2;
	
	fd2=dup(1);//save stdout
	printf("new:fd2=%d\n",fd2);
	
	fd1=open("test",O_CREAT|O_RDWR, S_IRWXU);
	close(1);
	dup(fd1);//1---> test
	printf("hello world\n");

	close(1);
	dup(fd2);//reset 1--->stdout 
	printf("i love you \n");
	return 0;
}





