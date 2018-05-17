#include "LoyaltyAccount.h"
#include<stdlib.h>
#include<stdio.h>

void loyaltyAccountDebit(LoyaltyAccount* loyaltyAccount, float value){
	if(value > loyaltyAccount->balance){
		printf("Insufficient Funds!\n");
	}
	else{
		loyaltyAccount->balance -= value;
	}
}

void loyaltyAccountCredit(LoyaltyAccount* loyaltyAccount, float value){
	loyaltyAccount->balance += value;
	loyaltyAccount->bonus += value/100;
}

void loyaltyAccountEarnBonus(LoyaltyAccount* loyaltyAccount){
	loyaltyAccount->balance += loyaltyAccount->bonus;
	loyaltyAccount->bonus = 0.0;
}

