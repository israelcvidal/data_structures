#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "Bucket.h"
#include<stdlib.h>

Bucket* createBucket(int size){
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->size = size;
    bucket->array = create();
}
int insertBucket(Bucket* bucket, int key){
    int occupied = sizeof(bucket->array);
    if(occupied < bucket->size){
        insert(bucket, key);
    }
    else{
//        TODO: CONTINUE FROM HERE!
    }
}
void removeBucket(Bucket* bucket, int key);
LinkedList* searchBucket(Bucket* bucket, int key);
void freeBucket(Bucket* bucket);
