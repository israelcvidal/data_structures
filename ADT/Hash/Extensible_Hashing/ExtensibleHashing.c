#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "ExtensibleHashing.h"
#include <stdlib.h>
#include <stdio.h>


ExtensibleHashing* createHashTable(int n);
void insertHashTable(ExtensibleHashing* extensibleHashing, int key);
LinkedList* searchHashTable(ExtensibleHashing* extensibleHashing, int key);
void removeHashTable(ExtensibleHashing* extensibleHashing, int key);
void freeHashTable(ExtensibleHashing* extensibleHashing);
int getBucket(ExtensibleHashing* extensibleHashing, int key);
void printHashTable(ExtensibleHashing* extensibleHashing);
