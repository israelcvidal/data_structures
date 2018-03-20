#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedList LinkedList;

struct linkedList{
	int inf;
	LinkedList* next;
};

LinkedList* create();
LinkedList* insert(LinkedList* list, int value);
void printList(LinkedList* list);
void recursivePrint(LinkedList* list);
void reversePrint(LinkedList* list);
int empty(LinkedList* list);
LinkedList* search(LinkedList* list, int value);
LinkedList* removeList(LinkedList* list, int value);
LinkedList* recursiveRemove(LinkedList* list, int value);
void freeList(LinkedList* list);

#endif