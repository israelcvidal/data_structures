#include "BankList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//int id = 0;

	printf("Creating empty list...\n");
	LinkedList* list = createList();

	printf("Inserting Bank Account...\n");
	list = insert(list, BANKACCOUNT, 2);

	printf("Inserting Savings Account...\n");
	list = insert(list, SAVINGSACCOUNT, 1);

	printf("Inserting Loyalty Account...\n");
	list = insert(list, LOYALTYACCOUNT, 0);

	printf("printList:\n");
	printList(list);

	printf("Crediting Savings Account. Value: 10\n");	
	LinkedList* savingsAccount = search(list, 1);
	credit(savingsAccount, 10);

	printf("printList:\n");
	printList(list);

	printf("Debting Savings Account. Value: 5.5\n");	
	debit(savingsAccount, 5.5);

	printf("printList:\n");
	printList(list);

	printf("Checking account 0:\n");
	printf("%f\n", ((LoyaltyAccount*)list->inf)->balance);

	printf("Crediting Loyalty Account. Value: 100\n");	
	LinkedList* loyaltyAccount = search(list, 0);
	credit(loyaltyAccount, 100);

	printf("Checking Loyalty Account's bonus:\n");
	printf("%f\n",  ((LoyaltyAccount*)list->inf)->bonus);

	printf("printList:\n");
	printList(list);

	printf("Transfering 50.00 from id:0 to id:1\n");
	debit(search(list, 0), 50.00);
	credit(search(list, 1), 50.00);

	printf("printList:\n");
	printList(list);

	printf("Earning Interests from Saving Account with id:1\n");
	savingsAccountEarnInterests((SavingsAccount*)search(list, 1)->inf);

	printf("printList:\n");
	printList(list);

	printf("Earning Bonus from Loyalty Account with id:0\n");
	loyaltyAccountEarnBonus((LoyaltyAccount*)search(list, 0)->inf);

	printf("printList:\n");
	printList(list);

	printf("removeList: id:1\n");
	list = removeList(list, 1);
	printList(list);

	printf("freeList...\n");
	freeList(list);

	return 0;

}