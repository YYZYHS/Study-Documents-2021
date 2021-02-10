#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

void fun1(int signo)
{
	printf("in fun1\n");
}

void fun2(int signo)
{
	printf("in fun2\n");
}

int main(int argc, char *argv[])
{
	sighandler_t previous = NULL;
	
	previous = signal(SIGINT,fun1);
	if(previous == NULL)
	{
		printf("return fun addr is NULL\n");
	}
	previous = signal(SIGINT,fun2);
	if(previous == fun1)
	{
		printf("return fun addr is fun1\n");
	}
	previous = signal(SIGQUIT,fun1);
	if(previous == NULL)
	{
		printf("return fun addr is NULL\n");
	}
	return 0;
}

