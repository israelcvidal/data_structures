#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include "hashTable.h"
#include <stdlib.h>


HashTable* createHashTable(int n){
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
	hashTable->numberOfKeys = n;
	hashTable->array = (LinkedList**)malloc(sizeof(LinkedList*)*(n/2));
	for (int i = 0; i < n/2; ++i){
		hashTable->array[i] = create();
	}

	return hashTable;
}

void insertHashTable(HashTable* hashTable, int key){
	int bucket = key%(hashTable->numberOfKeys/2);
	hashTable->array[bucket] = insert(hashTable->array[bucket], key);
}

HashTable* searchHashTable(HashTable* hashTable, int key){
	int bucket = key%(hashTable->numberOfKeys/2);
	return search(hashTable->array[bucket], key);
}

HashTable* removeHashTable(HashTable* hashTable, int key){
	return NULL;
}

void freeHashTable(HashTable* hashTable){
	return NULL;
}
