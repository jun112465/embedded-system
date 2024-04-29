#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLINE 100 


int readline(int fd, char *str);

// 이름있는 파이프를 통해 읽은 내용을 프린트한다.
int main(){
    int fd;
    char str[MAXLINE];

    unlink("myPIPE");
    mkfifo("myPIPE", 0660);

    fd = open("myPIPE", O_RDONLY);

    while(readline(fd, str)){
        printf("%s\n", str);
    }

    close(fd);

    return 0;
}

int readline(int fd, char *str){

    int n; 
    do{
        n = read(fd, str, 1);
    }while(n > 0 && *str++ != NULL);
    
    return (n>0);
}
