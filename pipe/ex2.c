#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXLINE 100

// 파이프를 통해 자식에서 실행되는 명령어 출력을 받아 프린트한다. 
int main(){

    int n, pid, fd[2];
    char line[MAXLINE];
    int status;

    // create pipe
    pipe(fd); 

    if((pid=fork())==0){
        // child process
        close(fd[0]);
        // copy write pipe to STDOUT
        dup2(fd[1], 1);
        close(fd[1]);

        // pipe will get this data
        printf("[%d] : Hello From Child Process\n", getpid());
        printf("[%d] : Good Bye~ From Child Process\n", getpid());

        exit(0);
    }else{
        wait(&status);
        printf("fd[1] : %d\n", fd[1]);
        printf("STDOUT_FILENO : %d\n", STDOUT_FILENO);
        close(fd[1]);
        while((n = read(fd[0], line, MAXLINE))>0){
            line[n] = '\0';
            write(STDOUT_FILENO, line, n);
            printf("%s", line);
            printf("----------------------------------------------------\n");
        }
            
    }
       

    exit(0);
}
