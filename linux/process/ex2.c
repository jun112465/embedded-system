#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int my_system(const char *cmd_string);

int main(){

	int status;

	if((status = my_system("date")) < 0)
		perror("my_system error\n");
	printf("exit code : %d\n", WEXITSTATUS(status));

	if((status = my_system("hello")) < 0)
		perror("my_system error\n");
	printf("exit code : %d\n", WEXITSTATUS(status));

	if((status = my_system("ls -al")) < 0)
		perror("my_system error\n");
	printf("exit code : %d\n", WEXITSTATUS(status));
	
	return 0;
}

int my_system(const char *cmd_string){

	int pid, status;

	if(cmd_string == NULL) 
		return 1;

	pid = fork();

	if(pid == -1) {
		printf("process creation failed\n");
		return -1;
	}
	if(pid == 0){
		execl("/bin/sh", "sh", "-c", cmd_string, NULL);
		exit(127);
	}

	//waiting
	waitpid(pid, &status, 0);
	if(WIFEXITED(status))printf("process terminated normally\n");
	else printf("process terminated abnormally\n");

	return 0;
}
