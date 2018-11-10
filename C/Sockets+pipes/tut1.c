#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DATA "Bright star, would I were steadfast as thou art..."
/* This program creates a pipe, then forks.
The child communicates to the parent over the pipe.
Notice that a pipe is a one-way communications
device. I can write to the ouput socket
(sockets[1], the second socket of the array returned 
by pipe()) abd read from the input socket (sockets[0]),
but not visa versa.
*/ 

main(){
    int sockets[2], child;

    /* Create a pipe */
    if (pipe(sockets) < 0) {
        perror("Opening stream socket pair");
        exit(-1);
    }

    if ((child = fork()) == -1){
        perror("Fork error");
    }
    else if (child) {
        char buf[1024];

        close(sockets[1]);
        if (read(sockets[0], buf, sizeof(buf)) < 0)
            perror("Message read error");
        
        printf("-->%s\n", buf);
        close(sockets[0]);
    } else {

        close(sockets[0]);
        if (write(sockets[1], DATA, sizeof(DATA)) < 0){
            perror("writing message");
        }
        close(sockets[1]);
    }
}