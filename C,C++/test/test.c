#include <stdio.h>
#include <stdint.h>

void to_binary(uint32_t n);

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
    // struct a
    // {
    //     int a;
    //     int b;
    //     int c;
    //     char d;
    //     double e;
    // };

    // struct a TEST = {0};

    // printf("%d %d %d %c %lf\n", TEST.a, TEST.b, TEST.c, TEST.d, TEST.e);

    // bit calculation
    int b = 64;
    int c = (uint32_t)64 << 16u;


    printf("decimal:%d, hex:%x bin:", b, b);
    to_binary(b);
    printf("\n");

    printf("decimal:%d, hex:%x bin:", c, c);
    to_binary(c);
    printf("\n");

    return 0;
}

void to_binary(uint32_t n){
    uint32_t data = n; //32bit형 int인 data를 선언한다
	for(int i=31; i>=0; i--) { //순서대로 출력하기위해 31부터 0까지 출력한다
		printf("%d", (data >> i) & 0x01); //데이터를 i번만큼 Shift한것을 1과 AND 연산한다
	}
}