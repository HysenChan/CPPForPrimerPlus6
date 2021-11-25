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
	Time operator-(const Time& t)const;
	Time operator*(double n) const;
	friend Time operator*(double m, const Time& t);
	friend void operator<<(std::ostream& os, const Time& t);
	void show()const;
	~Time();

private:
	int hours;
	int minutes;
};
