#include <stdio.h>
#include "partition.h"
#include <stdlib.h>

int main()
{
    int size = 5;
    int p[5] = {0};
    printf("Creating partition with size %d!\n", size);
    simpleCreateUnionFind(p, size);
    printPartition(p, size);

    int u = 2, v = 4;
    printf("Make Union of partitions of %d and %d\n", u, v);
    simpleSafeUnion(p, u, v);
    printPartition(p, size);

    printf("Representant of %d is %d\n", u, simpleFind(p, u));

    printf("%d and %d hasSamePartition? %s\n", u, v, hasSamePartition(p, u, v) ? "True": "False");

    return 0;
}
