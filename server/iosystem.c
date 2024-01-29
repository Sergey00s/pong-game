#include "iosystem.h"


int iosystem_init(iosystem_t *iosystem, char *path, size_t size)
{
	iosystem->path = path;
	iosystem->shm_fd = shm_open(path, O_CREAT | O_RDWR, 0644);
	if (iosystem->shm_fd == -1)
	{
		perror("shm_open");
		exit(1);
		return -1;
	}
	if (ftruncate(iosystem->shm_fd, size) == -1)
	{
		perror("ftruncate");
		exit(1);
		return -1;
	}
	iosystem->shm_size = size;	
	iosystem->size = size;
	iosystem->sem = sem_open(path, O_CREAT, 0644, 1);
	if (iosystem->sem == SEM_FAILED)
	{
		perror("sem_open");
		exit(1);
		return -1;
	}
	iosystem->addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, iosystem->shm_fd, 0);
	return 0;
}

int iosystem_destroy(iosystem_t *iosystem)
{
	if (munmap(iosystem->addr, iosystem->size) == -1)
	{
		perror("munmap");
		exit(1);
		return -1;
	}
	if (sem_close(iosystem->sem) == -1)
	{
		perror("sem_close");
		exit(1);
		return -1;
	}
	if (sem_unlink(iosystem->path) == -1)
	{
		perror("sem_unlink");
		exit(1);
		return -1;
	}
	if (shm_unlink(iosystem->path) == -1)
	{
		perror("shm_unlink");
		exit(1);
		return -1;
	}
	return 0;
}