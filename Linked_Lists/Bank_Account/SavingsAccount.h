typedef struct savingsAccount SavingsAccount;

struct savingsAccount{
	float balance;
};

void savingsAccountDebit(SavingsAccount* savingsAccount, float value);
void savingsAccountCredit(SavingsAccount* savingsAccount, float value);
void savingsAccountEarnInterests(SavingsAccount* savingsAccount);
