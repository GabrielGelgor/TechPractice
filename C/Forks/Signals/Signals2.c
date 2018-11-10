#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void hello(int signum){
    printf("Hello World!\n");
}

int main(){
    //When signal SIGUSR1 arises, execute hello.
    signal(SIGUSR1, hello);

    //Raise signal SIGUSR1.
    raise(SIGUSR1);
}