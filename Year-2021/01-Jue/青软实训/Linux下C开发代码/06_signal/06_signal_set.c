
#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	sigset_t set;
	int ret = 0;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	ret = sigismember(&set, SIGINT);
	printf("ret = %d\n", ret);
	return 0;
}

