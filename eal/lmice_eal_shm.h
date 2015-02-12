#ifndef LMICE_EAL_SHM_H
#define LMICE_EAL_SHM_H

#include <stdint.h>

#if defined(__APPLE__) || defined(__LINUX__)
#include <sys/mman.h>
#elif defined(_WIN32)
#include "lmice_eal_shm_win.h"
#endif

struct lmice_shm_s
{
    int fd;
    int size;
    uint64_t addr;
    char name[32];
};

typedef struct lmice_shm_s lmice_shm_t;

int eal_shm_create(lmice_shm_t* shm);

int eal_shm_destroy(lmice_shm_t* shm);

int eal_shm_open(lmice_shm_t* shm, int mode);

int eal_shm_close(lmice_shm_t* shm);

void eal_shm_zero(lmice_shm_t* shm);

int eal_shm_open_readonly(lmice_shm_t* shm);
int eal_shm_open_readwrite(lmice_shm_t* shm);



#endif /** LMICE_EAL_SHM_H */
