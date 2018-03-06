#include "DoublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>



DoublyLinkedList* create(){
	return NULL;
}

DoublyLinkedList* insert(DoublyLinkedList* list, int value){
	DoublyLinkedList* newList = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
	if(newList == NULL){
		printf("Could not allocate memory!\n");
		exit(1);
	}
	newList->inf = value;
	newList->next = list;
	newList->prev = NULL;

	if(list != NULL){
		list->prev = newList;
	}

	return newList;
}

void printList(DoublyLinkedList* list){
	DoublyLinkedList* p;
	for(p = list; p != NULL; p = p->next){
		printf("%d\t", p->inf);
	}
	printf("\n");

}

void recursivePrint(DoublyLinkedList* list){
	if(!empty(list)){
		printf("%d\t", list->inf);
		recursivePrint(list->next);
	}
	else{
		printf("\n");
	}
}
void reversePrint(DoublyLinkedList* list){
	if(!empty(list)){
		reversePrint(list->next);
		printf("%d\t", list->inf);
	}

}

int empty(DoublyLinkedList* list){
	return list == NULL;
}

DoublyLinkedList* search(DoublyLinkedList* list, int value){
	DoublyLinkedList* p;
	for(p = list; p != NULL; p = p->next){
		if(p->inf == value){
			return p;
		}
	}
	return NULL;
}

DoublyLinkedList* removeList(DoublyLinkedList* list, int value){
	DoublyLinkedList* p = list;
	
	while(p != NULL && p->inf != value){
		p = p->next;
	}

	// If contains element
	if(p != NULL){
		// Element is the head 
		if (p->prev == NULL){
			list =  p->next;
		}
		else{
			p->prev->next = p->next;
		}

		if(p->next!=NULL){
			p->next->prev = p->prev;
		}
		free(p);

	}

	return list;
}
DoublyLinkedList* recursiveRemove(DoublyLinkedList* list,  int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			list = list->next;
			free(list->prev);
		}
		else{
			list->next = recursiveRemove(list->next, value);
		}
	}
	
	return list;
}

void freeList(DoublyLinkedList* list){
	DoublyLinkedList* p = list;
	DoublyLinkedList* next = NULL;
	while(p != NULL){
		next = p->next;
		free(p);
		p = next;
	}

}