#include "BankList.h"
#include<stdlib.h>
#include<stdio.h>

void* createAccount(int type){
	if(type == BANKACCOUNT){
		BankAccount* bankAccount = (BankAccount*) malloc(sizeof(BankAccount));
		bankAccount->balance = 0.0;
		return bankAccount;

	} else if(type == SAVINGSACCOUNT){
		SavingsAccount* savingsAccount = (SavingsAccount*) malloc(sizeof(SavingsAccount));
		savingsAccount->balance = 0.0;
		return savingsAccount;

	} else if(type == LOYALTYACCOUNT){
		LoyaltyAccount* loyaltyAccount = (LoyaltyAccount*) malloc(sizeof(LoyaltyAccount));
		loyaltyAccount->balance = 0.0;
		loyaltyAccount->bonus = 0.0;

		return loyaltyAccount;
	} else{
		printf("INVALID TYPE! \n");
		return NULL;	
	} 
}

LinkedList* createList(){
	return NULL;
}

LinkedList* insert(LinkedList* list, int type, int id){
	LinkedList* prev = NULL;
	LinkedList* p = list;

	while(p!=NULL && p->id < id){
		prev = p;
		p = p->next;
	}


	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
	newList->inf = createAccount(type);
	newList->type = type;
	newList->id = id;

	if(newList == NULL){
		printf("Could not allocate memory!\n");
		exit(1);
	}

	// insert element at the head
	if(prev == NULL){
		newList->next = list;
		list = newList;
	}
	else{
		newList->next = prev->next;
		prev->next = newList;
	}
	return list;
}

void printList(LinkedList* list){
	LinkedList* p;
	for(p = list; p != NULL; p = p->next){
		float balance;

		switch(p->type){
			case BANKACCOUNT: 
				balance = ((BankAccount*)p->inf)->balance;
			break;

			case SAVINGSACCOUNT:
				balance = ((SavingsAccount*)p->inf)->balance;
			break;

			case LOYALTYACCOUNT:
				balance = ((LoyaltyAccount*)p->inf)->balance;
			break;

			default: 
				printf("INVALID TYPE!\n");
				exit(0);
			break;
		}
		printf("ID: %d, BALANCE: %f\t", p->id, balance);
	}
	printf("\n");

}

void recursivePrint(LinkedList* list){
	if(!empty(list)){
		float balance;

		switch(list->type){
			case BANKACCOUNT: 
				balance = ((BankAccount*)list->inf)->balance;
			break;

			case SAVINGSACCOUNT:
				balance = ((SavingsAccount*)list->inf)->balance;
			break;

			case LOYALTYACCOUNT:
				balance = ((LoyaltyAccount*)list->inf)->balance;
			break;

			default: 
				printf("INVALID TYPE!\n");
				exit(0);
			break;
		}
		printf("ID: %d, BALANCE: %f\t", list->id, balance);
		recursivePrint(list->next);
	}
	else{
		printf("\n");
	}
}

void reversePrint(LinkedList* list){
	if(!empty(list)){
		reversePrint(list->next);

		float balance;
		switch(list->type){
			case BANKACCOUNT: 
				balance = ((BankAccount*)list->inf)->balance;
			break;

			case SAVINGSACCOUNT:
				balance = ((SavingsAccount*)list->inf)->balance;
			break;

			case LOYALTYACCOUNT:
				balance = ((LoyaltyAccount*)list->inf)->balance;
			break;

			default: 
				printf("INVALID TYPE!\n");
				exit(0);
			break;
		}
		printf("ID: %d, BALANCE: %f\t", list->id, balance);
	}

}

int empty(LinkedList* list){
	return list == NULL;
}

LinkedList* search(LinkedList* list, int id){
	LinkedList* p;
	for(p = list; p != NULL; p = p->next){
		if(p->id == id){
			return p;
		}
	}
	return NULL;
}

LinkedList* removeList(LinkedList* list, int id){
	LinkedList* prev = createList();
	LinkedList* p = list;
	
	while(p != NULL && p->id != id){
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

LinkedList* recursiveRemove(LinkedList* list,  int id){
	if(!empty(list)){
		// if element is the head
		if(list->id == id){
			LinkedList* aux = list;
			list = list->next;
			free(aux);
		}
		else{
			list->next = recursiveRemove(list->next, id);
		}
	}
	
	return list;
}

void freeList(LinkedList* list){
	LinkedList* p = list;
	LinkedList* next = NULL;
	while(p != NULL){
		next = p->next;
		free(p->inf);
		free(p);
		p = next;
	}
}

void debit(LinkedList* list, float value){
	switch(list->type){
		case BANKACCOUNT: 
			bankAccountDebit((BankAccount*)list->inf, value);
		break;

		case SAVINGSACCOUNT:
			savingsAccountDebit((SavingsAccount*)list->inf, value);
		break;

		case LOYALTYACCOUNT:
			loyaltyAccountDebit((LoyaltyAccount*)list->inf, value);
		break;

		default: 
			printf("INVALID TYPE");
		break;
	}
}

void credit(LinkedList* list, float value){
	switch(list->type){
		case BANKACCOUNT: 
			bankAccountCredit((BankAccount*)list->inf, value);
		break;

		case SAVINGSACCOUNT:
			savingsAccountCredit((SavingsAccount*)list->inf, value);
		break;

		case LOYALTYACCOUNT:
			loyaltyAccountCredit((LoyaltyAccount*)list->inf, value);
		break;

		default: 
			printf("INVALID TYPE");
		break;
	}
}

