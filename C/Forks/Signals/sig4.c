#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

//Response to signal
void hello(){
    printf("Hello World!\n");
}

int main(){

    //Declaring pids
    pid_t pid;
    pid_t ppid;

    //Initializing signal catch
    signal(SIGUSR1, hello);

    //forking process
    pid = fork();

    //if child, send sigusr1, then exit. If parent, wait for termination of child.
    if (pid == 0){
        ppid = getppid();
        kill(ppid, SIGUSR1);
        exit(0);
    }else{
        wait(NULL);
    }
}