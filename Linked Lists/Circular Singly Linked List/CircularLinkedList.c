#include "CircularLinkedList.h"
#include <stdlib.h>
#include <stdio.h>



CircularLinkedList* create(){
	return NULL;
}

CircularLinkedList* insert(CircularLinkedList* list, int value){
	CircularLinkedList* newList = (CircularLinkedList*) malloc(sizeof(CircularLinkedList));
	CircularLinkedList* p = list;

	if(newList == NULL){
		printf("Could not allocate memory!\n");
		exit(1);
	}

	newList->inf = value;

	if(empty(list)){
		newList->next = newList;
	}
	else{
		while(p->next != list){
			p = p->next;
		}
		p->next = newList;
		newList->next = list;
	}
	
	return newList;
}

void printList(CircularLinkedList* list){
	CircularLinkedList* p = list;
	
	if(!empty(p)) do {
		printf("%d\t", p->inf);
		p = p->next;
	} while(p!=list);
		
	printf("\n");
}

void recursiveAuxPrint(CircularLinkedList* head, CircularLinkedList* list){
	if(list!=head){
		printf("%d\t", list->inf);
		recursiveAuxPrint(head, list->next);
	}
	else{
		printf("\n");
	}
}

void recursivePrint(CircularLinkedList* list){
	if(!empty(list)){
		printf("%d\t", list->inf);
		recursiveAuxPrint(list, list->next);
	}
	else{
		printf("\n");
	}
}

int empty(CircularLinkedList* list){
	return list == NULL;
}

CircularLinkedList* search(CircularLinkedList* list, int value){
	CircularLinkedList* p = list;

	if(!empty(p)) do{
		if(p->inf == value)
			return p;
		p = p->next;
	} while(p!=list);

	return NULL;
}

CircularLinkedList* removeList(CircularLinkedList* list, int value){
	CircularLinkedList* prev = create();
	CircularLinkedList* p = list;
	
	if(!empty(p) && p->inf != value) do{
		prev = p;
		p = p->next;

	} while(p != list && p->inf != value);

	// If contains element
	if(!empty(p) && p->inf == value){
		// Element is the head 
		if (prev == NULL){
			CircularLinkedList* aux = p;
			// finding last element
			while(aux->next != list){
				aux = aux->next;
			}
			aux->next = p->next;
			if(list!=p->next){
				list =  p->next;
			}
			else list = NULL;
		}
		else{
			prev->next = p->next;
		}
		free(p);
	}

	return list;
}

void updateHeader(CircularLinkedList* list, CircularLinkedList* oldHead, CircularLinkedList* newHead){
	if(!empty(list)){
		if(list->next == oldHead){
			list->next = newHead;
		}
		else{
			updateHeader(list->next, oldHead, newHead);
		}
	}
}

CircularLinkedList* recursiveAuxRemove(CircularLinkedList* head, CircularLinkedList* list, int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			CircularLinkedList* aux = list;
			list = list->next;
			free(aux);
		}
		else{
			list->next = recursiveAuxRemove(head, list->next, value);
		}
	}
	
	return list;
}


CircularLinkedList* recursiveRemove(CircularLinkedList* list,  int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			updateHeader(list, list, list->next);

			CircularLinkedList* aux = list;
			list = list->next;
			free(aux);
		}
		else{
			list->next = recursiveAuxRemove(list, list->next, value);
		}
	}
	
	return list;
}

void freeList(CircularLinkedList* list){

	CircularLinkedList* p = list;
	CircularLinkedList* next = NULL;
	if(!empty(list)) do{
		next = p->next;
		free(p);
		p = next;
	} while(p!=list);

}