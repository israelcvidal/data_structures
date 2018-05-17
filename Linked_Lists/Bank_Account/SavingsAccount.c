#include "SavingsAccount.h"
#include<stdlib.h>
#include<stdio.h>

void savingsAccountDebit(SavingsAccount* savingsAccount, float value){
	if(value > savingsAccount->balance){
		printf("Insufficient Funds!\n");
	}
	else{
		savingsAccount->balance -= value;
	}
}

void savingsAccountCredit(SavingsAccount* savingsAccount, float value){
	savingsAccount->balance += value;
}

void savingsAccountEarnInterests(SavingsAccount* savingsAccount){
	savingsAccount->balance += (savingsAccount->balance * 0.05/100);
}

