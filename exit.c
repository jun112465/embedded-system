#include <stdio.h>
#include <stdlib.h>

static void exit_handler1(void);
static void exit_handler2(void);

int main(){
	atexit(exit_handler1);
	atexit(exit_handler2);

	printf("main end\n");
	exit(0);
}

static void exit_handler1(void){
	printf("first exit handler\n");
}

static void exit_handler2(void){
	printf("second exit handler\n");
}
