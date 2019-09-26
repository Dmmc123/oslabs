#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (void) {
    const char string_original[] = "Hellow";
    unsigned const n = (int)strlen(string_original);
    char string_empty[n];

    int p[2];
    int pid;
    // opening the pipe
    pipe(p);
    if ((pid = fork()) > 0) {
        // in the parent main process
        // writing data to pipe
        write(p[1], string_original, n);
    }
    else {
        // in the child process
        // getting data from pipe
        read(p[0], string_empty, n);
        // printing the data we got from the pipe
        printf("%s", string_empty);
    }

    return 0;
}