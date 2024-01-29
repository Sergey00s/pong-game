#ifndef __IOSYSTEM_H__
#define __IOSYSTEM_H__

#include <sys/types.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

typedef struct {
	int fd;
	char *path;
	int shm_fd;
	int shm_size;
	void *addr;
	sem_t *sem;
	size_t size;
} iosystem_t;



int iosystem_init(iosystem_t *iosystem, char *path, size_t size);








#endif