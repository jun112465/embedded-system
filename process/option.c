#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Usage : %s <option> [string]\n", argv[0]);

	for(int i=1; i<argc; i++){
		if(strcmp(argv[i], "-i") == 0){
			printf("option i : %s\n", argv[i+1]);
		}

		if(strcmp(argv[i], "-o") == 0){
			printf("option o : %d\n", atoi(argv[i+1]));
		}
	}

	return 0;
}
