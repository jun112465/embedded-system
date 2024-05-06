#include <stdio.h>

int main(){
    // check UP
    /*
    int a = 0x12345678;
    char *cp = (char*)&a;

    for(int i=0; i<sizeof(int); i++){
        printf("%x", *cp);
        cp++;
    }
    */

    // check static
    static int a = 1;
    a = 3;
    printf("%d", a);

    return 0;
}