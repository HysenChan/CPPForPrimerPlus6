#include"mytime0.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::addHr(int h)
{
	hours += h;
}

void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}

//Time Time::sum(const Time& t) const
//{
//	Time sum;
//	sum.minutes = minutes + t.minutes;
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//	return sum;
//}

Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time& t) const
{
	Time diff;
	long totalMinutes = hours * 60 + minutes;
	long totalDiffMinutes = t.hours * 60 + t.minutes;
	long leftTime = totalMinutes - totalDiffMinutes;
	diff.hours = leftTime / 60;
	diff.minutes = leftTime % 60;
	return diff;
}

Time Time::operator*(double n) const
{
	Time mult;
	long totalMinutes = hours * n * 60 + minutes * n;
	mult.hours = totalMinutes / 60;
	mult.minutes = totalMinutes % 60;
	return mult;
}

Time operator*(double m, const Time& t)
{
	Time mult;
	long totalMinutes = t.hours * m * 60 + t.minutes * m;
	mult.hours = totalMinutes / 60;
	mult.minutes = totalMinutes % 60;
	return mult;
}

//void operator<<(std::ostream& os, const Time& t)
//{
//	os << t.hours << " hours," << t.minutes << " minutes.\n";
//}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours," << t.minutes << " minutes.\n";
	return os;
}

void Time::show() const
{
	std::cout << "hours:" << hours << ",minutes:" << minutes << std::endl;
}

Time::~Time()
{
}
