#pragma once
#include "Bucket.h"

typedef struct directory Directory;
typedef unsigned char byte;

struct directory{
    int globalDepth;
    int n;
    int bucketSize;
    Bucket** array;
};

Directory* createDirectory(int bucketSize, int globalDepth);
Directory* insertDirectory(Directory* directory, int key);
LinkedList* searchDirectory(Directory* directory, int key);
void freeDirectory(Directory* directory);
void printDirectory(Directory* directory);
byte getKey(int value, unsigned int leastBits);
Directory* doubleDirectory(Directory* directory);
Directory* recursiveInsertDirectory(Directory* directory, int key);
