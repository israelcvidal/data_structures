typedef struct hashTable HashTable;

struct hashTable{
	int numberOfKeys;
	LinkedList** array;
};

HashTable* createHashTable(int n);
void insertHashTable(HashTable* hashTable, int key);
HashTable* searchHashTable(HashTable* hashTable, int key);
HashTable* removeHashTable(HashTable* hashTable, int key);
void freeHashTable(HashTable* hashTable);
