#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#define MSGSIZE 16
#define READ    0
#define WRITE   1

char* phrase = "YEET";

main(){
    int fd[2], bytesRead;
    char message [100];
    pipe (fd);

    if (fork() == 0){
        close(fd[READ]);
        write(fd[WRITE],phrase,strlen(phrase)+1);
        close(fd[WRITE]);
    } else {
        close(fd[WRITE]);
        bytesRead = read(fd[READ],message,100);
        printf ("Read %d bytes: %s\n", bytesRead, message);
        close(fd[READ]);
    }
}