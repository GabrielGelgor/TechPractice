#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

void main(void){
    pid_t pid;
    int   i;
    char  buf[BUF_SIZE];

    fork();                                /* Everything above this is the same in both parent and child. */
    pid = getpid();
    for (i = 1; i <= MAX_COUNT; i++){
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));         /* We use write as it is unbuffered! Having it buffered as with fprint, we would run the risk over mixing both parent and child process outputs. */
    }

}