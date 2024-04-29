#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo);

int main(){

    // set signal handler
    newact.sa_handler = sigint_handler;
    // block all signals
    sigfillset(&newact.sa_mask);

    // set new action on SIGINT
    sigaction(SIGINT, &newact, &oldact);


    while(1){
        printf("PRESS Ctrl+c\n");
        sleep(1);
    }

    
    return 0;
}

void sigint_handler(int signo){
    printf("--Manage SIGNAL : SIGINT--\n");
    printf("PRESS again to exit\n");
    sigaction(SIGINT, &oldact, NULL);
}
