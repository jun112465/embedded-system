#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


// shared memory size
#define SHMSZ 27

int main(){

    int shmid;
    key_t key;
    char *shm_addr, *s;

    // shared memory key 
    key = 12345;

    // create shared memory and get shared memory id 
    if(shmid = shmget(key, SHMSZ, IPC_CREAT | 0666) < 0){
        perror("shmget");
        exit(1);
    }

    printf("shmid : %d\n", shmid);
    // connect shared memory to process (get address of shared memory)
    if((shm_addr = shmat(shmid, NULL, 0)) == (char*)-1){
        perror("shmat");
        exit(1);
    }
    // write data to shared memory  
    s = shm_addr;
    for(char c='a'; c<='z'; c++){
        *s++ = c;
        // *(shm++) = c 와 같음
    }
    *s = '\0';

    //detatch
    shmdt(shm_addr);
    // another process will delete shared memory after reading data

    return 0;
}
