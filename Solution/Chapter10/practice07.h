#pragma once
#include<iostream>

class Plorg
{
public:
	Plorg(const char *name = "Plorga", int ci = 50);
	void changeName(const char* name);
	void changeCi(int newCi);
	void ShowPlorg()const;
	~Plorg();

private:
	char fullname[20];
	int ci;
};
