#include"CheckingAccount.h"
#include"SavingsAccount.h"
#include"CreditCard.h"
#include"BankAccount.h"
#include<list>
#include<iostream>

int main() {
	std::list<BankAccount*> accountList;
	BankAccount *testAccount = new CheckingAccount(112251, 250.52, "Testy McGoo");
	testAccount->deposit(358.21);
	testAccount->withdrawl(48.53, "Gas");
	accountList.push_back(testAccount);
	testAccount = new SavingsAccount(212251, 1130.52, "Testy McGoo");
	testAccount->withdrawl(400, "Cash Withdrawl");
	testAccount->deposit(1000);
	accountList.push_back(testAccount);
	testAccount = new CreditCard(312251, 1130.52, "Testy McGoo");
	testAccount->withdrawl(1024.23, "Rent");
	accountList.push_back(testAccount);

	int x = accountList.size();

	for (int i = 0; i < x; i++) {
		accountList.front()->printTransHistory();
		accountList.push_back(accountList.front());
		accountList.pop_front();

	}
	for (auto itr = accountList.begin(); itr != accountList.end(); itr++) {
		BankAccount*& act = *itr;
		delete act;
	}
	if (accountList.empty() == false) {
		accountList.erase(accountList.begin(), accountList.end());
	}
	if (accountList.empty() == true) {
		std::cout << "Empty list.\n";
	}
	system("pause");

	return 0;
}