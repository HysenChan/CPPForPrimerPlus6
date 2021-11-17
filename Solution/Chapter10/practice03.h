#pragma once
#include<iostream>

class Golf
{
public:
	Golf();
	Golf(const char* name, int hc);
	void setHandicap(int hc);
	void showgolf();
	~Golf();

private:
	static const int Len = 40;
	char fullname[Len];
	int handicapValue;
};