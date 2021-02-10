#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSZ 2048

int main(int argc, char *argv[])
{
	int shmid;
	int ret;
	key_t key;
	char *shmadd;
	//1��ftok��ȡ��ֵ
	key = ftok(".", 2012); 
	if(key == -1)
	{
		perror("ftok");
	}
	/*���������ڴ�*/
	shmid = shmget(key, BUFSZ, SHM_R|SHM_W|IPC_CREAT);	
	if(shmid < 0) 
	{ 
		perror("shmget"); 
		exit(-1); 
	} 
	/*ӳ��*/
	shmadd = shmat(shmid, NULL, 0);
	if(shmadd < 0)
	{
		perror("shmat");
		_exit(-1);
	}
	/*���������������ڴ���*/
	printf("copy data to shared-memory\n");
	bzero(shmadd, BUFSZ);
	strcpy(shmadd, "data in shared memory\n");
	return 0;
}

