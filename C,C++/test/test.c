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
    /*
    static int a = 1;
    a = 3;
    printf("%d", a);
    */

    // check struct init
    struct a
    {
        int a;
        int b;
        int c;
        char d;
        double e;
    };

    struct a TEST = {0};

    printf("%d %d %d %c %lf\n", TEST.a, TEST.b, TEST.c, TEST.d, TEST.e);

    return 0;
}