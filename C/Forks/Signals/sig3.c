#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void hello(int signum){
    printf("Hello World!\n");
}

int main(){

    //When SIGINT is raised, execute hello.
    signal(SIGINT, hello);

    //Loop forever.
    while(1);
}