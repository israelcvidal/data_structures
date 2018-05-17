#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>



LinkedList* create(){
	return NULL;
}

LinkedList* insert(LinkedList* list, int value){
	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
	if(newList == NULL){
		printf("Could not allocate memory!\n");
		exit(1);
	}
	newList->inf = value;
	newList->next = list;

	return newList;
}

void printList(LinkedList* list){
	LinkedList* p;
	for(p = list; p != NULL; p = p->next){
		printf("%d\t", p->inf);
	}
	printf("\n");

}

void recursivePrint(LinkedList* list){
	if(!empty(list)){
		printf("%d\t", list->inf);
		recursivePrint(list->next);
	}
	else{
		printf("\n");
	}
}
void reversePrint(LinkedList* list){
	if(!empty(list)){
		reversePrint(list->next);
		printf("%d\t", list->inf);
	}

}

int empty(LinkedList* list){
	return list == NULL;
}

LinkedList* search(LinkedList* list, int value){
	LinkedList* p;
	for(p = list; p != NULL; p = p->next){
		if(p->inf == value){
			return p;
		}
	}
	return NULL;
}

LinkedList* removeList(LinkedList* list, int value){
	LinkedList* prev = create();
	LinkedList* p = list;
	
	while(p != NULL && p->inf != value){
		prev = p;
		p = p->next;

	}

	// If contains element
	if(p != NULL){
		// Element is the head 
		if (prev == NULL){
			list =  p->next;
		}
		else{
			prev->next = p->next;
		}
		free(p);
	}

	return list;
}
LinkedList* recursiveRemove(LinkedList* list,  int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			LinkedList* aux = list;
			list = list->next;
			free(aux);
		}
		else{
			list->next = recursiveRemove(list->next, value);
		}
	}
	
	return list;
}

void freeList(LinkedList* list){
	LinkedList* p = list;
	LinkedList* next = NULL;
	while(p != NULL){
		next = p->next;
		free(p);
		p = next;
	}

}