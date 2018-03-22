#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "Bucket.h"
#include "Directory.h"

typedef struct extendibleHashing ExtendibleHashing;

struct extendibleHashing{
    Directory* directory;
};

ExtendibleHashing* createExtendibleHashing(int bucketSize, int globalDepth);
void insertExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
LinkedList* searchExtendibleHashing(ExtendibleHashing* extendibleHashing, int key);
void freeExtendibleHashing(ExtendibleHashing* extendibleHashing);
void printExtendibleHashing(ExtendibleHashing* extendibleHashing);
