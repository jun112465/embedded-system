#include <stdio.h>

int main(){
	extern char **environ;
	for(char **ptr = environ; *ptr != 0; ptr++){
		printf("%s\n", *ptr);
	}
	return 0;
}
