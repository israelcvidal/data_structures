#include "BankAccount.h"
#include<stdlib.h>
#include<stdio.h>

void bankAccountDebit(BankAccount* bankAccount, float value){
	if(value > bankAccount->balance){
		printf("Insufficient Funds!\n");
	}
	else{
		bankAccount->balance -= value;
	}
}

void bankAccountCredit(BankAccount* bankAccount, float value){
	bankAccount->balance += value;
}