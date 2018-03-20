#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"

typedef struct extensibleHashing ExtensibleHashing;

struct extensibleHashing{
    int numberOfKeys;
    LinkedList** array;
};

ExtensibleHashing* createHashTable(int n);
void insertHashTable(ExtensibleHashing* extensibleHashing, int key);
LinkedList* searchHashTable(ExtensibleHashing* extensibleHashing, int key);
void removeHashTable(ExtensibleHashing* extensibleHashing, int key);
void freeHashTable(ExtensibleHashing* extensibleHashing);
int getBucket(ExtensibleHashing* extensibleHashing, int key);
void printHashTable(ExtensibleHashing* extensibleHashing);
