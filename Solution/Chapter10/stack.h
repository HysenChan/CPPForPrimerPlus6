#pragma once

typedef unsigned long Item;

class Stack
{
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull()const;
	bool push(const Item& item);
	bool pop(Item& item);

private:
	enum{Max = 10};
	Item items[Max];
	int top;
};
