#pragma once
#include<iostream>
struct customer
{
	char fullname[35];
	double payment;
};
typedef customer Items;

class Stacks
{
public:
	Stacks();
	bool isempty()const;
	bool isfull()const;
	bool push(const Items& item);
	bool pop(Items& item);
	void showStacks()const;
	~Stacks();

private:
	Items items[3];
	int top;
};