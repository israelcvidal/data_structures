#include "HashTable.h"
#include "../../Linked_Lists/Singly_Linked_List/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

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
    int bucket = getBucket(hashTable, key);
    hashTable->array[bucket] = insert(hashTable->array[bucket], key);
}

LinkedList* searchHashTable(HashTable* hashTable, int key){
    int bucket = getBucket(hashTable, key);
    return search(hashTable->array[bucket], key);
}

void removeHashTable(HashTable* hashTable, int key){
    int bucket = getBucket(hashTable, key);
    hashTable->array[bucket] = removeList(hashTable->array[bucket], key);
}

void freeHashTable(HashTable* hashTable){
    for (int i = 0; i < hashTable->numberOfKeys/2; ++i){
        freeList(hashTable->array[i]);
    }
    free(hashTable);
}

int getBucket(HashTable* hashTable, int key){
    return key%(hashTable->numberOfKeys/2);
}

void printHashTable(HashTable* hashTable){
    for (int i = 0; i < hashTable->numberOfKeys/2; ++i){
        printf("BUCKET %d:\n", i);
        printList(hashTable->array[i]);
        printf("\n");
    }
}
