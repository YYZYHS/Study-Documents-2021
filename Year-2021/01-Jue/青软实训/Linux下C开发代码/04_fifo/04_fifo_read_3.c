
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
	
	ret = unlink("my_fifo");	//删除上次运行后残留的fifo
	if(ret<0)
	{
		perror("unlink fifo");
	}
	ret = mkfifo("my_fifo", S_IRUSR|S_IWUSR);
	if(ret != 0)
	{
		perror("mkfifo");
	}
	fd = open("my_fifo", O_RDONLY|O_NONBLOCK);
	if(fd<0)
	{
		perror("open fifo");
	}
	while(1)
	{
		char recv[100];
		
		bzero(recv, sizeof(recv));
		read(fd, recv, sizeof(recv));
		printf("read from my_fifo buf=[%s]\n",recv);
		sleep(1);
	}
	return 0;
}




