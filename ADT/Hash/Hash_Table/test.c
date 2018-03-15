#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	srand(time(NULL));

	HashTable* hashTable;
	int n, r;
	printf("Choose the number n of keys accepted by the Hash Table:\n");
	scanf("%d", &n);

	printf("CREATING HASH TABLE WITH %d BUCKETS...\n", n/2);
	hashTable = createHashTable(n);

	r = rand() % n;
	printf("INSERTING KEY %d\n", r);
	insertHashTable(hashTable, r);

	r = rand() % n;
	printf("INSERTING KEY %d\n", r);
	insertHashTable(hashTable, r);

	r = rand() % n;
	printf("INSERTING KEY %d\n", r);
	insertHashTable(hashTable, r);

	r = rand() % n;
	printf("INSERTING KEY %d\n", r);
	insertHashTable(hashTable, r);

	r = rand() % n;
	printf("INSERTING KEY %d\n", r);
	insertHashTable(hashTable, r);

	r = rand() % n;
	printf("SEARCHING KEY %d\n", r);
	printf("%s", searchHashTable(hashTable, r) ? "FOUND\n" : "NOT FOUND\n");

	printf("HASH TABLE:\n");
	printHashTable(hashTable);


	r = rand() % n;
	printf("TRYING TO REMOVE KEY %d", r);
	removeHashTable(hashTable, r);

	printf("FREEING HASH TABLE...\n");
	freeHashTable(hashTable);

	return 0;
}