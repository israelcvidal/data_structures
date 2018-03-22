#include "Bucket.h"
#include<stdlib.h>

Bucket* createBucket(int size, int localDepth){
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->size = size;
    bucket->localDepth = localDepth;
    bucket->occupied = 0;
    bucket->array = create();
    return bucket;
}

void insertBucket(Bucket* bucket, int key){
    if(bucket->occupied < bucket->size){
        bucket->array = insert(bucket->array, key);
        bucket->occupied+=1;
    }
    else{
        exit(EXIT_FAILURE);
    }
}

void removeBucket(Bucket* bucket, int key){
    bucket->array = removeList(bucket->array, key);
}

LinkedList* searchBucket(Bucket* bucket, int key){
    return search(bucket->array, key);
}

void freeBucket(Bucket* bucket){
    freeList(bucket->array);
    free(bucket);
}

void printBucket(Bucket* bucket){
    printList(bucket->array);
}

int sizeList(LinkedList* list){
    int count = 0;
    LinkedList* head = list;
    while (head!=NULL) {
        count+=1;
        head = head->next;
    }
    return count;
}
