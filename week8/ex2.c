#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KB 1024LU
#define MB 1024LU * KB
#define SIZE 10LU * MB

int main() {
    for (int i = 0; i < 10; i++) {
        void * ptr = malloc(SIZE);
        memset(ptr, 0, SIZE);
        sleep(1);
    }
    return 0;
}