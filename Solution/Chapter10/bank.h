#pragma once
#include<iostream>
#include<string>

class Bank
{
public:
	Bank();
	Bank(const std::string& n, const std::string& acc, double store);
	void deposit(double price);
	void takeOut(double price);
	void show()const;
	~Bank();
private:
	std::string name;
	std::string account;
	double storageMoney;
};