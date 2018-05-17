typedef struct bankAccount BankAccount;

struct bankAccount{
	float balance;
};

void bankAccountDebit(BankAccount* bankAccount, float value);

void bankAccountCredit(BankAccount* bankAccount, float value);