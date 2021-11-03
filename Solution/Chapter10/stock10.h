#ifndef STOCK10_H_
#define STOCK10_H_

#include<string>
#include <iostream>

class Stock
{
public:
	Stock();
	Stock(const std::string& co, long n, double pr);
	~Stock();
	//void acquire(const std::string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const void show();

private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
};

#endif // !STOCK10_H_
