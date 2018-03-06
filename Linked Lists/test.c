#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	LinkedList* list = create();
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 10);
	printList(list);

	list = recursiveRemove(list, 2);
	printList(list);

	list = recursiveRemove(list, 2);
	printList(list);

	freeList(list);
	return 0;
}