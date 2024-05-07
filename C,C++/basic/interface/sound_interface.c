#include <stdio.h>

typedef struct{
    void (*sound)(void);
}Interface;

// dog interface
void dog_sound(){
    printf("wal wal\n");
}
void interface_make_dog(Interface *interface){
    interface->sound = dog_sound;
}

// cat interface
void cat_sound(){
    printf("meow meow\n");
}
void interface_make_cat(Interface *interface){
    interface->sound = cat_sound;
}

int main(){
    Interface dog, cat;

    interface_make_dog(&dog);
    interface_make_cat(&cat);

    dog.sound();
    cat.sound();
}

