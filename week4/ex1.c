#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int n = 7;
    pid_t pid = fork();
    if (pid == 0) printf("Hello from child [%d - %d]\n", getpid(), n);
    else printf("Hello from parent [%d - %d]\n", getpid(), n);
    return 0;

    /* Output of the program that was run 10 times is as follows
     * PID in the output increases by 1 because
     * the processes are proceeded 1 by 1 as well
     * Moreover, for each process the content of int stays non-changing
     * (that's why we see 7's in each output line)
     * because each process has it's copy of original data
        Hello from parent [26764 - 7]
        Hello from child [26765 - 7]
        Hello from parent [26766 - 7]
        Hello from child [26767 - 7]
        Hello from parent [26768 - 7]
        Hello from child [26769 - 7]
        Hello from parent [26770 - 7]
        Hello from child [26771 - 7]
        Hello from parent [26772 - 7]
        Hello from child [26773 - 7]
        Hello from parent [26774 - 7]
        Hello from child [26775 - 7]
        Hello from parent [26776 - 7]
        Hello from child [26777 - 7]
        Hello from parent [26778 - 7]
        Hello from child [26779 - 7]
        Hello from parent [26780 - 7]
        Hello from child [26781 - 7]
        Hello from parent [26782 - 7]
        Hello from child [26783 - 7] */
}
