#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define COUNT_LIMIT 10

int count = 0;
sem_t sem;

void *thread_function(void *arg){
    int thread_id = *(int *)arg;


    for(int i=0; i<10; i++){
        //sem_wait(&sem);


        count++;
        printf("Thread : %d: Count = %d\n", thread_id, count);

        usleep(20000);
        //sem_post(&sem);
    }

    pthread_exit(NULL);
}

int main(){

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    //sem_init(&sem, 0, 1);
    sem_init(&sem, 0, 5);

    for(int i=0; i<NUM_THREADS; i++){
        thread_args[i] = i+1;
        pthread_create(threads+i, NULL, thread_function, thread_args+i);
    }

    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&sem);

    return 0;
}
