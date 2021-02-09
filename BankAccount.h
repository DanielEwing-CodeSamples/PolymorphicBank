#pragma once
#include<string>
class BankAccount
{
protected:
	int accountNumber;
	double balance;
	std::string ownersName;


public:
	BankAccount();
	void virtual deposit(double _amount) = 0;
	void virtual printTransHistory() = 0;
	void virtual withdrawl(double _amount, std::string _description) = 0;

};



