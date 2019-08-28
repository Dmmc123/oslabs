#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("i\nsize: %lu bytes, value: %d\n", sizeof(i), i);
    printf("f\nsize: %lu bytes, value: %f\n", sizeof(f), f);
    printf("d\nsize: %lu bytes, value: %lf", sizeof(d), d);
    return 0;
}