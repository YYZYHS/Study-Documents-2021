#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd_pipe[2];
	char buf[] = "hello world";
	pid_t pid;
	
	if (pipe(fd_pipe) < 0)
		perror("pipe");
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	if (pid == 0)
	{
		write(fd_pipe[1], buf, strlen(buf));
		_exit(0);
	}
	else
	{
		wait(NULL);
		memset(buf, 0, sizeof(buf)); //初始化
		read(fd_pipe[0], buf, sizeof(buf));
		printf("buf=[%s]\n", buf);
	}
	return 0;
}


