
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char recv[100];
	
	ret = mkfifo("my_fifo", S_IRUSR|S_IWUSR);//创建命名管道
	if(ret != 0)
	{
		perror("mkfifo");
	}
	printf("before open\n");
	fd = open("my_fifo", O_RDONLY); //打开管道
	if(fd<0)
	{
		perror("open fifo");
	}
	printf("after open and before read\n");
	bzero(recv, sizeof(recv));
	read(fd, recv, sizeof(recv));
	printf("read from my_fifo buf=[%s]\n",recv);
	return 0;
}




