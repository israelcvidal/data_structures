#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "Directory.h"
#include "Bucket.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Directory* createDirectory(int bucketSize, int globalDepth){
    Directory* directory = (Directory*)malloc(sizeof(Directory));
    directory->bucketSize = bucketSize;
    directory->globalDepth = globalDepth;
    directory->array = (Bucket**)malloc(sizeof(Bucket*)*pow(2, globalDepth));

    Bucket* bucket;
    if(bucketSize > 0){
        bucket = createBucket(bucketSize, 0);
        for (int i = 0; i < pow(2, globalDepth); ++i){
            directory->array[i] = bucket;
        }
    }
    return directory;
}

Directory* insertDirectory(Directory* directory, int key){
    int index = (int)getKey(key, directory->globalDepth);
    Bucket* bucket = directory->array[index];
    if(sizeList(bucket->array) < bucket->size){
        insertBucket(bucket, key);
    }
    else{
        if(directory->globalDepth == bucket->localDepth)
            directory = doubleDirectory(directory);
        directory = recursiveInsertDirectory(directory, key);
    }

    return directory;
}

LinkedList* searchDirectory(Directory* directory, int key){
    int index = (int)getKey(key, directory->globalDepth);
    return searchBucket(directory->array[index], key);
}

Directory* doubleDirectory(Directory* directory){
    Directory* doubledDirectory = createDirectory(directory->bucketSize, directory->globalDepth+1);
    for(int i=0; i<pow(2, doubledDirectory->globalDepth); i++){
        doubledDirectory->array[i] = directory->array[getKey(i, directory->globalDepth)];
    }
    free(directory);

    return doubledDirectory;
}

Directory* recursiveInsertDirectory(Directory* directory, int key){
    int index = (int)getKey(key, directory->globalDepth);
    Bucket* bucket = directory->array[index];
    Bucket* splitBucket1 = createBucket(bucket->size, bucket->localDepth+1);
    Bucket* splitBucket2 = createBucket(bucket->size, bucket->localDepth+1);

    int first = 1;
    int splitBucketIndex1;
    int splitBucketIndex2;


    for(int i=0; i<pow(2, directory->globalDepth); i++){
        if(directory->array[i] == bucket){
            if(first){
                first = 0;
                directory->array[i] = splitBucket1;
                splitBucketIndex1 = i;
            }
            else{
                directory->array[i] = splitBucket2;
                splitBucketIndex2 = i;
                break;
            }
        }
    }

    LinkedList* p = bucket->array;

    while(p!=NULL){
        int auxKey = getKey(p->inf, bucket->localDepth+1);
        if(auxKey  == splitBucketIndex1){
            insertBucket(splitBucket1, p->inf);
        }
        else if(auxKey  == splitBucketIndex2){
                insertBucket(splitBucket2, p->inf);
            }
        p = p->next;
    }
    freeBucket(bucket);
    directory = insertDirectory(directory, key);
    return directory;
}

void freeDirectory(Directory* directory){
    for(int i=0; i<pow(2, directory->globalDepth); i++){
        if(directory->array!=NULL)
            freeBucket(directory->array);
    }
    free(directory);
}

void printDirectory(Directory* directory){
    for(int i=0; i<pow(2, directory->globalDepth); i++){
        printf("DIR[%d]:\n", i);
        printBucket(directory->array[i]);
        printf("\n");
    }
}

byte getKey(int value, unsigned int leastBits){
    int nbit_mask = (1 << leastBits) - 1;
    return (byte)(value & nbit_mask);
}

void removeDirectory(Directory* directory, int key){
    int index = (int)getKey(key, directory->globalDepth);
    removeBucket(directory->array[index], key);
}
