#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int var = 8;

void *thread_1(void *arg)
{
	while(1)
	{
		printf("this is my new thread1 var++\n");
		var++;
		sleep(1);
	}
	return NULL;
}

void *thread_2(void *arg)
{
	while(1)
	{
		printf("this is my new thread2 var = %d\n", var);
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;

	/*创建两个线程*/
	pthread_create(&tid1, NULL, thread_1, NULL);
	pthread_create(&tid2, NULL, thread_2, NULL);
	while(1);
	return 0;
}