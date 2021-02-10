#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem_g, sem_p;
char ch = 'a';

void *pthread_g(void *arg)
{
	while(1)
	{
		sem_wait(&sem_g);//-1
		ch++;
		sleep(1);
		sem_post(&sem_p);//+1
	}
}

void *pthread_p(void *arg)
{
	while(1)
	{
		sem_wait(&sem_p);//-1
		printf("%c", ch);
		fflush(stdout);
		sem_post(&sem_g);//+1
	}
}

int main(void)
{
	pthread_t tid1, tid2;

	sem_init(&sem_g, 0, 0);
	sem_init(&sem_p, 0, 1);

	pthread_create(&tid1, NULL, pthread_g, NULL);
	pthread_create(&tid2, NULL, pthread_p, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
