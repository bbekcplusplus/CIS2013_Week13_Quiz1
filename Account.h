#include<iostream>
#include <string>
int const TOTAL_ACCOUNTS = 10;
int accountNumberStore[TOTAL_ACCOUNTS] = { 0,0,0,0,0,0,0,0,0,0 };

using namespace std;
class Account
{
	/* member variable declaration*/
private:
	int accountNumber;
	string ownerName;
	int balance;
	/* Member function declaration*/
public:
	Account();
	Account(int accountNumber, string ownerName, int balance);
	int withdraw(int amount);
	void deposit(int amount);
	int getAccountNumber();
	string getOwnerName();
	float getBalance();
	void setUserData();
	void displayAccountInfo(); 
};