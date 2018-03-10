#include "SortedLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Creating empty list...\n");
	LinkedList* list = create();

	printf("Inserting element in list...\n");
	list = insert(list, 1);

	printf("Inserting element in list...\n");
	list = insert(list, 2);

	printf("Inserting element in list...\n");
	list = insert(list, 10);

	printf("printList:\n");
	printList(list);

	printf("reversePrint\n");
	reversePrint(list);
	printf("\n");

	printf("recursivePrint:\n");
	recursivePrint(list);

	printf("recursiveRemove: 2\n");
	list = recursiveRemove(list, 2);
	printList(list);

	printf("removeList:\n");
	list = removeList(list, 10);
	printList(list);

	printf("is empty? %s\n", empty(list) ? "true": "false");
	
	printf("Is 1 in list? %s\n", (search(list, 1)!=NULL) ? "true": "false");

	LinkedList* list2 = create();
	list2 = insert(list2, 1);

	printf("equal? %s\n", equal(list, list2) ? "true" : "false");
	
	
	printf("freeList...\n");
	freeList(list);
	return 0;
}