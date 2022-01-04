#pragma once
#include<iostream>

class Cd
{
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual~Cd();
	virtual void Report()const;
	virtual Cd& operator=(const Cd& d);

private:
	char* performers;
	char* label;
	int selections;
	double playtime;
};

class Classic :public Cd
{
public:
	Classic(const char* s0, const  char* s1, const  char* s2, int n, double x);
	Classic(char* s0, Cd& rs);
	Classic();
	~Classic();
	void Report()const;
	Classic& operator=(const Classic& c);

private:
	char* mainworks;
};
