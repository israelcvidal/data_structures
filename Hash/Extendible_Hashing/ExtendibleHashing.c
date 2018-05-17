#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "ExtendibleHashing.h"
#include "Bucket.h"
#include "Directory.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ExtendibleHashing* createExtendibleHashing(int bucketSize){
    ExtendibleHashing* extendibleHashing = (ExtendibleHashing*)malloc(sizeof(ExtendibleHashing));

    extendibleHashing->directory = createDirectory(bucketSize, 1);
    return extendibleHashing;
}

void insertExtendibleHashing(ExtendibleHashing* extendibleHashing, int key){
    extendibleHashing->directory = insertDirectory(extendibleHashing->directory, key);
}

LinkedList* searchExtendibleHashing(ExtendibleHashing* extendibleHashing, int key){
    return searchDirectory(extendibleHashing->directory, key);
}

void freeExtendibleHashing(ExtendibleHashing* extendibleHashing){
    freeDirectory(extendibleHashing->directory);
    free(extendibleHashing);
}

void printExtendibleHashing(ExtendibleHashing* extendibleHashing){
    printDirectory(extendibleHashing->directory);
}

void removeExtendibleHashing(ExtendibleHashing* extendibleHashing, int key){
    removeDirectory(extendibleHashing->directory, key);
}
