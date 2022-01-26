#pragma once
#include<iostream>
#include<cstdlib>

class bad_hmean
{
public:
	bad_hmean(int a = 0, int b = 0) :v1(a), v2(b) {};
	void mesg();

private:
	double v1;
	double v2;
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << "," << v2 << "):" << "invalid arguments:a = -b \n";
}

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(int a = 0, int b = 0) :v1(a), v2(b) {};
	const char* mesg();
};

inline const char* bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

double hmean(double a, double b);

bool hmean(double a, double b, double* ans);

inline double hmean(double a, double b)
{
	if (a == -b)
	{
		//error1
		/*std::cout << "untenable arguments to hmean()\n";
		std::abort();*/

		//error2
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

inline double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}

inline double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg)
	{
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}

inline bool hmean(double a, double b, double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

class demo
{
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << " created\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destroyed\n";
	}
	void show()const
	{
		std::cout << "demo " << word << " lives!\n";
	}

private:
	std::string word;
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);