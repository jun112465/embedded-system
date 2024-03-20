#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo);
void intHandler(int signo);

int main(){

    // register signal handler 
    signal(SIGINT, intHandler);

    int sec = 0;

    alarm(5);

    while(1){
        sleep(1);
        printf("%d seconds passed..\n", ++sec);
    }
    return 0;
}

// SIGALM 처리 함수
void alarmHandler(int signo){
    printf("wake up~!");
    exit(0);
}

// SIGINT 처리 함수
void intHandler(int signo){
    printf("Interrupt Signal\n");
    printf("SIGNO : %d\n", signo);
    exit(0);
}
