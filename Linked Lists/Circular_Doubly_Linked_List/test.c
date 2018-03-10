#include "CircularDoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Creating empty list...\n");
	CircularDoublyLinkedList* list = create();

	printf("Inserting element at head of list...\n");
	list = insert(list, 1);

	printf("Inserting element at head of list...\n");
	list = insert(list, 2);

	printf("Inserting element at head of list...\n");
	list = insert(list, 10);

	printf("printList:\n");
	printList(list);

	printf("recursivePrint:\n");
	recursivePrint(list);

	printf("recursiveRemove: 2\n");
	list = recursiveRemove(list, 2);
	printList(list);

	// printf("removeList:\n");
	// list = removeList(list, 10);
	// printList(list);

	// printf("removeList:\n");
	// list = removeList(list, 2);
	// printList(list);

	// printf("removeList:\n");
	// list = removeList(list, 1);
	// printList(list);

	// printf("removeList:\n");
	// list = removeList(list, 10);
	// printList(list);

	printf("is empty? %s\n", empty(list) ? "true": "false");
	
	printf("Is 1 in list? %s\n", (search(list, 1)!=NULL) ? "true": "false");

	printf("freeList...\n");
	freeList(list);
	return 0;
}