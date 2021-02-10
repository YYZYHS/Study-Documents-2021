#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *arg)
{
	int i;
	static int test = 1213;

	for(i=0; i<5; i++)
	{
		printf("I am runing\n");
	}
	pthread_exit((void *)(&test));  
	return NULL;
}

int main(int argc, char *argv[])
{
	void *value_ptr;
	int ret = 0;
	pthread_t tid1;

	ret = pthread_create(&tid1, NULL, thread, NULL);
	if(ret != 0)
	{
		perror("pthread_create");
	}
	pthread_join(tid1, &value_ptr);
	printf("value_ptr = %d\n", *((int *)value_ptr));
	sleep(1);
	printf("I am leaving\n");
	while(1);
	return 0;
}