#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int pid;
void alarm_handler(int signo);

// 명령줄 인수로 받은 명령어 실행에 제한 시간을 둔다. 
int main(int argc, char *argv[]){

    int limit, child, status;

    signal(SIGALRM, alarm_handler);

    sscanf(argv[1], "%d", &limit);
    printf("limit : %d\n", limit);
    // after limit, SIGALRM
    alarm(limit);

    pid = fork();
    if(pid == 0){
        // child process
        // execvp(argv[2], &argv[2]);
        execlp(argv[2], argv[2], argv[3], NULL);
        fprintf(stderr, "%s : execution failed", argv[1]);
    }else{
        child = wait(&status);
        printf("[%d] child process %d terminated\n", getpid(), pid);
    }
   
    
    return 0;
}

void alarm_handler(int signo){
    printf("ALARM HANDLER %d\n", signo);
    printf("[ALARM] child process %d time out\n", pid);
}
