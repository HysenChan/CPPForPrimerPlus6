#pragma once

#include <iostream>
#include <valarray>
#include <string>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	void set(const T1& yr, const T2& bot);
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {}
	int Sum() const;
	void Show(int y) const;
	~Pair();
};

template <class T1, class T2>
void Pair<T1, T2>::set(const T1& yr, const T2& bot)
{
	a = yr;
	b = bot;
}

template <class T1, class T2>
int Pair<T1, T2>::Sum() const
{
	return b.sum();
}

template <class T1, class T2>
void Pair<T1, T2>::Show(int y) const
{
	for (int i = 0; i < y; i++)
	{
		std::cout << "\t\t" << a[i] << "\t\t" << b[i] << std::endl;
	}
}

template<class T1, class T2>
inline Pair<T1, T2>::~Pair()
{
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	PairArray b;
	std::string name;
	int yrs;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	std::string& Label();
	int sum();
	void Show();
	~Wine();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	yrs = y;
	name = l;
	b.set(ArrayInt(yr, yrs), ArrayInt(bot, yrs));
}

Wine::Wine(const char* l, int y)
{
	yrs = y;
	name = l;
}

void Wine::GetBottles()
{
	ArrayInt yr(yrs), bot(yrs);
	std::cout << "Enter " << name << " data for " << yrs << " year(s):\n";
	for (int i = 0; i < yrs; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> yr[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> bot[i];
	}
	b.set(yr, bot);
}

std::string& Wine::Label()
{
	return name;
}

int Wine::sum()
{
	return b.Sum();
}

void Wine::Show()
{
	std::cout << "Wine: " << name << std::endl;
	std::cout << "\t\tYear\tBottles\n";
	b.Show(yrs);
}

inline Wine::~Wine()
{
}
