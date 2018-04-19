
#include "Account.h"
// Member functions definitions including default constructor
Account::Account()
{

}
void Account::setUserData() {

	int accountNumber, i;
	string ownerName;
	int balance;
	int flag = 1, flagAccount = 1;
	while (flag) {
		cout << "Please Enter an account number: " << endl;
		cin >> accountNumber;
		for (i = 0; i<TOTAL_ACCOUNTS; i++) {
			if (accountNumber == accountNumberStore[i]) {
				cout << "Account Number Already present! Account creation failed! " << endl;
				flag = 0;
				break;
			}
			/* condition for storing account number for checking existing account*/
			if (accountNumberStore[i] == 0 && flagAccount) {
				accountNumberStore[i] = accountNumber;
				flagAccount = 0;
			}
		}
		if (flag == 0) {
			flag = 1;
		}
		else {
			cout << "Account created with Account Number: " << accountNumber << endl;
			cout << "Please Enter Owner Name: " << endl;
			cin >> ownerName;
			cout << "Please Enter Opening Balance: " << endl;
			cin >> balance;
			/*Calling Parametrized constructure for saving data*/
			new (this) Account(accountNumber, ownerName, balance);

			flag = 0;
		}

	}
}
// Member functions definitions including parametrized constructor
Account::Account(int accountNumber, string ownerName, int balance)
{
	this->accountNumber = accountNumber;
	this->ownerName = ownerName;
	this->balance = balance;
}
/* getAccountNuber function defination*/
int Account::getAccountNumber() {

	return accountNumber;
}
/* getBalance function defination*/
float Account::getBalance() {
	return balance;
}
/* getOwnerName function defination*/
string Account::getOwnerName() {

	return ownerName;
}
/* displayAccountInfo function defination*/
void Account::displayAccountInfo() {
	cout << "*************User Account Information display**********" << endl;
	cout << "Owner Name: " << this->getOwnerName() << endl;
	cout << "Account Number: " << this->getAccountNumber() << endl;
	cout << "Balance: " << this->getBalance() << endl;
	cout << "*******************display End**************************" << endl;
}
/* function for depositing money*/
void Account::deposit(int amount) {
	this->balance += amount;
}
int Account::withdraw(int amount) {
	/* checking current balance in account
	* if amount is greater then current balance then we will show error or no withdraw
	* this->accountNumber will give current object account number
	*/
	if (amount>this->balance) {
		cout << "Current balance is less: current Amount( " << this->balance << ")" << endl;;
	}
	else {
		cout << " Balance before withdraw: " << this->balance << endl;
		cout << " Amount was withdraw: " << amount << endl;
		this->balance = this->balance - amount;
		cout << " Remaining Balance: " << this->balance << endl;
	}

}