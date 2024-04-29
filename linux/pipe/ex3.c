#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define READ 0 
#define WRITE 1
#define MAXLINE 100

// get two commands "ex) ls|wc" 
// 자식 프로세스에서 얻은 값을 부모 프로세스에서 입력으로 받기.  
int main(){

    char str[1024], line[MAXLINE];
    char *command1, *command2;
    int fd[2], n;

    printf("[my_shell]");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    if(strchr(str, '|') != NULL){
        command1 = strtok(str, "|");
        command2 = strtok(NULL, "|");
    }

    pipe(fd);

    if(fork() == 0){
        close(fd[READ]);
        dup2(fd[WRITE], 1);
        close(fd[WRITE]);
        execlp(command1, command1, NULL);
        perror("pipe");
    }else{
        close(fd[WRITE]);
        dup2(fd[READ], 0); // read pipe의 값을 표준입력으로 받을 수 있게 된다. 
        close(fd[READ]);

        execlp(command2, command2, NULL);
    }
    

    return 0;
}
