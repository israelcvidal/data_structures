#include "CircularDoublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>



CircularDoublyLinkedList* create(){
	return NULL;
}

CircularDoublyLinkedList* insert(CircularDoublyLinkedList* list, int value){
	CircularDoublyLinkedList* newList = (CircularDoublyLinkedList*) malloc(sizeof(CircularDoublyLinkedList));
	CircularDoublyLinkedList* p = list;

	if(newList == NULL){
		printf("Could not allocate memory!\n");
		exit(1);
	}

	newList->inf = value;

	if(empty(list)){
		newList->next = newList;
		newList->prev = newList;
	}
	else{
		while(p->next != list){
			p = p->next;
		}
		p->next = newList;
		newList->prev = p;
		newList->next = list;
	}
	
	return newList;
}

void printList(CircularDoublyLinkedList* list){
	CircularDoublyLinkedList* p = list;
	
	if(!empty(p)) do {
		printf("%d\t", p->inf);
		p = p->next;
	} while(p!=list);
		
	printf("\n");
}

void recursiveAuxPrint(CircularDoublyLinkedList* head, CircularDoublyLinkedList* list){
	if(list!=head){
		printf("%d\t", list->inf);
		recursiveAuxPrint(head, list->next);
	}
	else{
		printf("\n");
	}
}

void recursivePrint(CircularDoublyLinkedList* list){
	if(!empty(list)){
		printf("%d\t", list->inf);
		recursiveAuxPrint(list, list->next);
	}
	else{
		printf("\n");
	}
}

int empty(CircularDoublyLinkedList* list){
	return list == NULL;
}

CircularDoublyLinkedList* search(CircularDoublyLinkedList* list, int value){
	CircularDoublyLinkedList* p = list;

	if(!empty(p)) do{
		if(p->inf == value)
			return p;
		p = p->next;
	} while(p!=list);

	return NULL;
}

CircularDoublyLinkedList* removeList(CircularDoublyLinkedList* list, int value){
	CircularDoublyLinkedList* p = list;
	
	if(!empty(p) && p->inf != value) do{
		p = p->next;

	} while(p != list && p->inf != value);

	// If contains element
	if(!empty(p) && p->inf == value){
		// Element is the head 
		p->prev->next = p->next;
		p->next->prev = p->prev;
		if(list!=p->next){
			list =  p->next;
		}
		else list = NULL;
		
		free(p);
	}
	return list;
}


CircularDoublyLinkedList* recursiveAuxRemove(CircularDoublyLinkedList* head, CircularDoublyLinkedList* list, int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			printf("entrou\n");
			list->next->prev = list->prev;

			CircularDoublyLinkedList* aux = list;
			if(list != list->next){
				list = list->next;
			}
			else list = NULL;
			free(aux);
		}
		else if(list->next != head){
				list->next = recursiveAuxRemove(head, list->next, value);
			}	
	}
	
	return list;
}


CircularDoublyLinkedList* recursiveRemove(CircularDoublyLinkedList* list,  int value){
	if(!empty(list)){
		// if element is the head
		if(list->inf == value){
			list->prev->next = list->next;
			list->next->prev = list->prev;

			CircularDoublyLinkedList* aux = list;
			if(list != list->next){
				list = list->next;
			}
			else list = NULL;
			free(aux);
		}
		else{
			list->next = recursiveAuxRemove(list, list->next, value);
		}
	}
	
	return list;
}

void freeList(CircularDoublyLinkedList* list){

	CircularDoublyLinkedList* p = list;
	CircularDoublyLinkedList* next = NULL;
	if(!empty(list)) do{
		next = p->next;
		free(p);
		p = next;
	} while(p!=list);

}