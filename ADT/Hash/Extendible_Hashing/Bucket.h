#pragma once
#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"

typedef struct bucket Bucket;

struct bucket{
    int size;
    LinkedList* array;
};

Bucket* createBucket(int size);
int insertBucket(Bucket* bucket, int key);
void removeBucket(Bucket* bucket, int key);
LinkedList* searchBucket(Bucket* bucket, int key);
void freeBucket(Bucket* bucket);
