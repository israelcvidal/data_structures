#include "partition.h"

void simpleCreateUnionFind(int  p[], int  size){
    for(int i=0; i < size; i++)
        p[i] = -1;
}

int  simpleFind(int p[],int u){
    if(p[u] == -1){
        return u;
    }
    else{
        return simpleFind(p, p[u]);
    }
}
void  simpleSafeUnion(int p[], int u, int v){
    u = simpleFind(p, u);
    v = simpleFind(p, v);
    p[u] = v;
}

void printPartition(int p[], int size){
    for(int i=0; i<size; i++)
        printf("%d\t", p[i]);
    printf("\n");
}

int hasSamePartition(int p[], int u, int v){
    return p[u] == p[v] || p[u] == v || u == p[v];
}
