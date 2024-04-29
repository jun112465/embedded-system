#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <semaphore.h>


#define THREAD_NUM 5

void* printing(void *arg);

int main(){

    pthread_t threads[THREAD_NUM];
    int thread_args[THREAD_NUM];

    for(int i=0; i<THREAD_NUM; i++){
        thread_args[i] = i+1;
        pthread_create(threads+i, NULL, printing, thread_args+i);
    }

    for(int i=0; i<THREAD_NUM; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* printing(void *arg){
    int thread_num = *(int *)(arg);
    while(1){
        printf("[THREAD %d] Hello, world\n", thread_num);
        sleep(1);
    }
    pthread_exit(NULL);
}