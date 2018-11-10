/*exec(killall cat);     Send a SIGTERM signal to all cat programs.*/

#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
#define SIGILL  4
#define SIGTRAP 5
#define SIGABRT 6
#define SIGPOLL 7
#define SIGFRE  8
#define SIGKILL 9

/* 
Default actions of a signal:
Term: Terminate the process
Core: Terminate the process, but produce a core file dump that traces process state at time of termination
Ign: Ignore the signal
Stop: Stop the process (Cntrl-z)
Cont: The process will continue from being stopped.
*/

