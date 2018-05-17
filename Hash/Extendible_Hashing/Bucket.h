#pragma once
#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"

typedef struct bucket Bucket;

struct bucket{
    int size;
    int occupied;
    int localDepth;
    LinkedList* array;
};

Bucket* createBucket(int size, int localDepth);
void insertBucket(Bucket* bucket, int key);
void removeBucket(Bucket* bucket, int key);
LinkedList* searchBucket(Bucket* bucket, int key);
void freeBucket(Bucket* bucket);
void printBucket(Bucket* bucket);
int sizeList(LinkedList* list);
