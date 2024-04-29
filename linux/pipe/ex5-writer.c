#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLINE 1000


int main(){

    int fd, length, i;
    char message[MAXLINE];

    sprintf(message, "Hello from PID:%d", getpid());
    length = strlen(message)+1;
    
    do{
        fd = open("myPIPE", O_WRONLY);
        if(fd == -1) sleep(1);
    }while(fd == -1);

    while(1){
        write(fd, message, length);
        sleep(1);
    }

    close(fd);
    return 0;
}




