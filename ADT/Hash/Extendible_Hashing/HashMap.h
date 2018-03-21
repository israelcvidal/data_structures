#pragma once
#include "Bucket.h"

typedef struct hashMap HashMap;

struct hashMap{
    char* key;
    Bucket* bucket;
};

HashMap* createHashMap(char* key, Bucket* bucket);
void freeHashMap(HashMap* hashMap);
