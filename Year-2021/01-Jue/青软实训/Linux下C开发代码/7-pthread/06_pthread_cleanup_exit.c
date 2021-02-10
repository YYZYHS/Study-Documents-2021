#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void cleanup(void *arg)
{
	printf("clean up ptr = %s\n", (char *)arg);
	free((char *)arg);
}

void *thread(void *arg)
{
	char *ptr = NULL;

	printf("this is new thread\n");
	ptr = (char *)malloc(100);

	pthread_cleanup_push(cleanup, (void *)(ptr));

	bzero(ptr, 100);
	strcpy(ptr, "memory from malloc");

	printf("before exit\n");
	pthread_exit(NULL);
	sleep(3);

	printf("before pop\n");
	pthread_cleanup_pop(0);
	// pthread_cleanup_pop(1);
	return NULL;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	pthread_t tid1;

	ret = pthread_create(&tid1, NULL, thread, NULL);
	if(ret != 0)
	{
		perror("pthread_create");
	}
	pthread_join(tid1, NULL);
	printf("process is dying\n");
	return 0;
}