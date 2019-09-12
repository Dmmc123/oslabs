#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 5; i++) {
        fork();
        sleep(5);
    }
    return 0;

    /* Partial output for pstree command looked like this
     * 8 processes were created because each of 3 forks
     * doubled the amount of previously active processes
     * so we get 2^3 processes (2^n for general case)

     ──bash───process.exe─┬─process.exe─┬─process.exe───process.exe
                          │             └─process.exe
                          ├─process.exe───process.exe
                          └─process.exe

     * We got almost the same picture with 5 forks and 32 processes

       ──bash───process.exe─┬─process.exe─┬─process.exe─┬─process.exe─┬─process.exe───process.exe
                            │             │             │             └─process.exe
                            │             │             ├─process.exe───process.exe
                            │             │             └─process.exe
                            │             ├─process.exe─┬─process.exe───process.exe
                            │             │             └─process.exe
                            │             ├─process.exe───process.exe
                            │             └─process.exe
                            ├─process.exe─┬─process.exe─┬─process.exe───process.exe
                            │             │             └─process.exe
                            │             ├─process.exe───process.exe
                            │             └─process.exe
                            ├─process.exe─┬─process.exe───process.exe
                            │             └─process.exe
                            ├─process.exe───process.exe
                            └─process.exe
                          */
}
