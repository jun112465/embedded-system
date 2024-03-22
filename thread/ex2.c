#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define COUNT_TO_10 10000

int main(){
    pthread_t tid[10];

    void *thread_add(void*){
        while(1){
            printf("Thread Id : %lu\n", pthread_self());
            sleep(1);
        }
    }

    for(int i=0; i<3; i++){
        pthread_create(tid + i, NULL, thread_add, NULL);
        //pthread_join(tid[i], NULL); 모든 쓰레드를 생성하고 나서 join해야 여러 쓰레드가 동시에 실행될 수 있다. 
    }

    for(int i=0; i<3; i++){
        pthread_join(tid[i], NULL);
    }

    return 0;
}


