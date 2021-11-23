#pragma once
#include<iostream>
class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	//Time sum(const Time& t)const;
	Time operator+(const Time& t)const;
	void show()const;
	~Time();

private:
	int hours;
	int minutes;
};
