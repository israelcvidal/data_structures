#include "HashMap.h"
#include "Bucket.h"
#include<stdlib.h>


HashMap* createHashMap(char* key, Bucket* bucket){
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->key = key;
    hashMap->bucket = bucket;

    return hashMap;
}

void freeHashMap(HashMap* hashMap){
    freeBucket(hashMap->bucket);
    free(hashMap);
}
