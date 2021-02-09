#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int _accountNumber, double _balance, std::string _ownersName) {
	accountNumber = _accountNumber;
	ownersName = _ownersName;
	balance = _balance;
	transactionAmounts.push_back(_balance);
	transactionHistory.push_back("Account Creation");
}

double CheckingAccount::getBalance() {
	return balance;
}
int CheckingAccount::getAccountNumber() {
	return accountNumber;
}
std::string CheckingAccount::getAccountType() {
	return "Checking";
}
std::string CheckingAccount::getOwnersName() {
	return ownersName;
}
void CheckingAccount::deposit(double ammount) {
	balance += ammount;
	transactionAmounts.push_back(ammount);
	transactionHistory.push_back("Deposit");
}
void CheckingAccount::withdrawl(double ammount, std::string transName) {
	balance -= ammount;
	transactionAmounts.push_back(ammount);
	transactionHistory.push_back(transName);
}
void CheckingAccount::printTransHistory() {
	std::cout << "Hello " << ownersName << ", this is the history for your " << getAccountType() << " account, account number: " << accountNumber << ".\n";
	for (int i = 1; i < transactionAmounts.size()+1; i++) {
		std::cout << "		Transaction #" << i << ", ammount: $" << transactionAmounts.front() << " transaction type: " << transactionHistory.front() << ".\n";
		transactionAmounts.push_back(transactionAmounts.front());
		transactionAmounts.pop_front();
		transactionHistory.push_back(transactionHistory.front());
		transactionHistory.pop_front();
	}
	std::cout << "Current Balance: $" << balance << ".\n";
}