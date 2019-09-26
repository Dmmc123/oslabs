#include <stdio.h>
#include <signal.h>

int FLAG;

void kill_handler() {
    printf("Got SIGKILL signal\n");
    FLAG = 1;
}
void stop_handler() {
    printf("Got SIGSTOP signal\n");
    FLAG = 1;
}
void usr1_handler() {
    printf("Got SIGUSR1 signal\n");
    FLAG = 1;
}

int main (void) {
    signal(SIGKILL, kill_handler);
    signal(SIGSTOP, stop_handler);
    signal(SIGUSR1, usr1_handler);
    while(!FLAG);

    //  while sending this process to background
    //  and terminating with kill -SIGUSR1 <pid>
    //  this is printed
    //
    //  $ gcc ex4.c
    //  $ ./a.out &
    //  $ (getting <pid>)
    //  $ kill -SIGUSR1 <pid>
    //
    //  $ Got SIGUSR1 signal
    //  It happens because after terminating process
    //  with SIGUSR1 program catches the signal
    //  and runs usr1_handler function
    return 0;
}