#define BANKACCOUNT 0
#define SAVINGSACCOUNT 1
#define LOYALTYACCOUNT 2

#include "BankAccount.h"
#include "SavingsAccount.h"
#include "LoyaltyAccount.h"

typedef struct linkedList LinkedList;

struct linkedList{
	int type;
	int id;
	void *inf;
	LinkedList* next;
};

void* createAccount(int type);
LinkedList* createList();
LinkedList* insert(LinkedList* list, int type, int id);
void printList(LinkedList* list);
void recursivePrint(LinkedList* list);
void reversePrint(LinkedList* list);
int empty(LinkedList* list);
LinkedList* search(LinkedList* list, int id);
LinkedList* removeList(LinkedList* list, int id);
LinkedList* recursiveRemove(LinkedList* list, int id);
void freeList(LinkedList* list);

void debit(LinkedList* list, float value);
void credit(LinkedList* list, float value);

