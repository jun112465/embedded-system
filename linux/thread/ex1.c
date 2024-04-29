#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void test(){
    printf("another function\n");
}

void my_function(){
    printf("my_function\n");
}

void *difference1();
void (*difference2)();

int main(){
    // function_pointer
    printf("%p\n", my_function);
    printf("%p\n", &my_function);

    //difference1 = my_function;
    //printf("%p\n", difference1);
    
    difference2 = my_function;
    printf("%p\n", difference2);

    return 0;
}


