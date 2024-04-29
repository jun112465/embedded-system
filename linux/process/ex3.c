#include <stdio.h>
#include <unistd.h>

int cnt = 0;

int main(){
    pid_t pid;

    pid = fork();
    if(pid == 0){
        printf("pid : %d\n", getpid());
        sleep(1);
    }

    pid = fork();
    if(pid == 0){
        printf("pid : %d\n", getpid());
    }
}

