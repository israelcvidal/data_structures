typedef struct loyaltyAccount LoyaltyAccount;

struct loyaltyAccount{
	float balance;
	float bonus;
};

void loyaltyAccountDebit(LoyaltyAccount* loyaltyAccount, float value);
void loyaltyAccountCredit(LoyaltyAccount* loyaltyAccount, float value);
void loyaltyAccountEarnBonus(LoyaltyAccount* loyaltyAccount);
