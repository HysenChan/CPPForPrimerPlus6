#pragma once
#include<iostream>

class Cow
{
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow&);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow()const;

private:
	char name[20];
	char* hobby;
	double weight;
};
