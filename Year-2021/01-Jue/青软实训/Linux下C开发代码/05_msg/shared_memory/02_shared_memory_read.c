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
	
	key = ftok(".", 2012); 
	if(key==-1)
	{
		perror("ftok");
	}
	system("ipcs -m");
	/*�򿪹����ڴ�*/
	shmid = shmget(key, BUFSZ, SHM_R|SHM_W);	
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
		exit(-1);
	}
	/*�������ڴ�������*/
	printf("copy data from shared-memory\n");
	printf("data = [%s]\n", shmadd);
	/*���빲���ڴ�͵�ǰ����*/
	ret = shmdt(shmadd);
	if(ret < 0)
	{
		perror("shmdt");
		exit(1);
	}
	else
	{
		printf("deleted shared-memory\n");
	}
	/*ɾ�������ڴ�*/
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");
	return 0;
}

