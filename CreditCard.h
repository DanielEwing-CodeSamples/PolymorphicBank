#pragma once
#include "BankAccount.h"
#include<list>
#include<iostream>

class CreditCard :public BankAccount {
private:
	double balance;
	int accountNumber;
	std::string ownersName;
	std::list<std::string> transactionHistory;
	std::list<double> transactionAmounts;

public:
	CreditCard(int _accountNumber, double _balance, std::string _ownersName);
	double getBalance();
	int getAccountNumber();
	std::string getOwnersName();
	std::string getAccountType();
	void virtual deposit(double ammount);
	void virtual withdrawl(double ammount, std::string transName);
	void printTransHistory();
};


