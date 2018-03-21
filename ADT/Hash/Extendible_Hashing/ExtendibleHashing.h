#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "Bucket.h"
#include "HashMap.h"

typedef struct extendibleHashing ExtendibleHashing;

struct extendibleHashing{
    int numberOfKeys;
    int bucketSize;
    int maxPrefix;
    int prefixSize;
    HashMap** hashMaps;
};

ExtendibleHashing* createExtendibleHashing(int n, int bucketSize);
void insertExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
LinkedList* searchExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
void removeExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
void freeExtendibleHashing(ExtendibleHashing* extendibleHashing);
int getBucket(ExtendibleHashing* extendibleHashing, int key);
void printExtendibleHashing(ExtendibleHashing* extendibleHashing);
char* getBin(int number, void* n);
char* int2bin(int n);
