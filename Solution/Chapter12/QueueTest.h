#pragma once
#include<iostream>

class Customer
{
public:
	Customer() { arrive = processTime = 0; }
	void set(long when);
	long when()const { return arrive; }
	int ptime()const { return processTime; }
	~Customer();

private:
	long arrive;
	int processTime;
};

typedef	Customer Item;

class Queue
{
public:
	Queue(int qs = Q_SIZE);
	Queue();
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);

private:
	struct Node
	{
		Item item;
		struct Node* next;
	};
	enum
	{
		Q_SIZE = 10
	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
};