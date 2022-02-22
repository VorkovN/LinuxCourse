#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, char* argv[])
{
	key_t key1 = atoll(argv[1]);
	key_t key2 = atoll(argv[2]);
	key_t key3 = 512997;

	int shmid1 = shmget(key1, 1000, 0666);
	int shmid2 = shmget(key2, 1000, 0666);
	int shmid3 = shmget(key3, 1000, IPC_CREAT | 0666);

//	int shm1[100] = (int*)malloc(1000 * sizeof(int));
//	int shm2[100] = (int*)malloc(1000 * sizeof(int));

	int* shm1 = (int*)shmat(shmid1, NULL, 0);
	int* shm2 = (int*)shmat(shmid2, NULL, 0);
	int* shm3 = (int*)shmat(shmid3, NULL, 0);

	for (int i = 0; i < 100; i++)
		shm3[i] = shm1[i]+shm2[i];

	printf("%d\n", key3);

	shmdt (shm1);
	shmdt (shm2);
	shmdt (shm3);

	return 0;
}
