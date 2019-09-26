#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define A_SECOND 1
#define A_COUPLE_OF_SECONDS 2
#define SIGN_OF_LIVING for(int i = 1; ; i++) { \
                        printf("Second process is alive for %d seconds\n", i); \
                        sleep(A_SECOND); }

int main (void) {
    pid_t first_child, second_child;
    pid_t sent_pid;
    int p[2];

    // opening the pipe
    pipe(p);

    if ((first_child = fork()) == 0) {
        // first child process

        // getting the id of second child
        read(p[0], &sent_pid, sizeof(pid_t));

        sleep(A_COUPLE_OF_SECONDS);
        kill(sent_pid, SIGSTOP);
    }
    else if ((second_child = fork()) == 0) {
        // second child process

        SIGN_OF_LIVING
    }
    else {
        // parent's process

        // sending the id of second child
        write(p[1], &first_child, sizeof(pid_t));

        sleep(A_COUPLE_OF_SECONDS);

    }
    return 0;
}