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
    char *shm_addr;

    // shared memory key 
    key = 12345;

    // create shared memory and get shared memory id 
    if(shmid = shmget(key, SHMSZ, 0666) < 0){
        perror("shmget");
        exit(1);
    }
    // connect shared memory to process (get address of shared memory)
    if((shm_addr = shmat(shmid, NULL, 0)) == (char*)-1){
        perror("shmat");
        exit(1);
    }
    // read data from shared memory  
    printf("readed from shared memory : %s\n", shm_addr);

    // delete shared memory
    shmdt(shm_addr);
    shmctl(shmid, IPC_RMID, NULL);

    printf("shared memory deleted\n");

    return 0;
}
