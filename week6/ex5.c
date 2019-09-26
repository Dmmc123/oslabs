#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (void) {
    int pid;
    if ((pid = fork()) > 0) {
        //  in parent process
        sleep(10);
        kill(pid, SIGTERM);
    }
    else {
	//  in child process
        for (int i = 1; ; i++) {
            sleep(1);
            printf("I'm alive for %d seconds\n", i);
        }
    }
    return 0;
}