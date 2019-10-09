#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

#define KB 1024LU
#define MB 1024LU * KB
#define SIZE 10LU * MB

int main() {
    struct rusage usage;

    for (int i = 0; i < 10; i++) {
        void * ptr = malloc(SIZE);
        memset(ptr, 0, SIZE);
        getrusage(RUSAGE_SELF, &usage);

        printf("Maximum resident set size: %ld\n", usage.ru_maxrss);
        printf("Integral shared memory size: %ld\n", usage.ru_ixrss);
        printf("Integral unshared data size: %ld\n", usage.ru_idrss);
        printf("Integral unshared stack size: %ld\n", usage.ru_isrss);
        printf("Page reclaims (soft page faults): %ld\n", usage.ru_minflt);
        printf("Page faults (hard page faults): %ld\n", usage.ru_majflt);
        printf("Swaps: %ld\n\n", usage.ru_nswap);

        sleep(1);
    }
    return 0;
}