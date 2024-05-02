#include <stdio.h>

int main(){
    int a = 0x12345678;
    char *cp = (char*)&a;

    for(int i=0; i<sizeof(int); i++){
        printf("%x", *cp);
        cp++;
    }


    return 0;
}