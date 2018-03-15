#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"

typedef struct hashTable HashTable;

struct hashTable{
	int numberOfKeys;
	LinkedList** array;
};

HashTable* createHashTable(int n);
void insertHashTable(HashTable* hashTable, int key);
LinkedList* searchHashTable(HashTable* hashTable, int key);
void removeHashTable(HashTable* hashTable, int key);
void freeHashTable(HashTable* hashTable);
int getBucket(HashTable* hashTable, int key);
void printHashTable(HashTable* hashTable);