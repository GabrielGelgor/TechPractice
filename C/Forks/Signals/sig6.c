#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler3(int signum){
    printf("What did I do to you??\n");
    signal(SIGINT, SIG_DFL);    //Swap to our default handler.
}

void handler2(int signum){
    printf("Stop!\n");
    signal(SIGINT, handler3);   //swap to our third handler
}

void handler1(int signum){
    printf("Holy shit, ouch\n");
    signal(SIGINT, handler2);   //Swap to our second handler
}

int main(){
    printf("Hey man what's up\n");

    signal(SIGINT, handler1); //Start with our initial handler

    while(1);
}