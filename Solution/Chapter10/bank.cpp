#include"bank.h"

Bank::Bank()
{
	name = "no name";
	account = "no account";
	storageMoney = 0.0;
}

Bank::Bank(const std::string& n, const std::string& acc, double store)
{
	name = n;
	account = acc;
	storageMoney = store;
}

void Bank::deposit(double price)
{
	if (price < 0)
		std::cout << "Please enter more than 0 price:";
	else
		storageMoney += price;
}

void Bank::takeOut(double price)
{
	if (price < 0)
		std::cout << "Please enter more than 0 price:";
	else if (price > storageMoney)
		std::cout << "Your account not enough " << price;
	else
		storageMoney -= price;
}

void Bank::show() const
{
	using std::cout;
	using std::endl;
	cout << "name:" << name << endl;
	cout << "account:" << account << endl;
	cout << "storeMoney:" << storageMoney << endl;
}

Bank::~Bank()
{
}