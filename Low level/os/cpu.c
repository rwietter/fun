#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

int Spin(int x)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (1)
    {
        gettimeofday(&end, NULL);
        if ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) > x)
        {
            break;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0;
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1)
    {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
        exit(0);
    }
    return 0;
}