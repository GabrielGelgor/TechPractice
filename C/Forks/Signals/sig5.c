#include <signal.h>
#include <sys/signal.h>

void nothing(){ /* DO NOTHING*/ }

int main(){

    signal(SIGINT, nothing); //same as signal(SIGINT, SIG_IGN);

    while(1);
}