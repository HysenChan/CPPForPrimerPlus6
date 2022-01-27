#pragma once
#include<iostream>
#include<cstdlib>

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

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

class Sales
{
public:
	enum { MONTHS = 12 };
	class bad_index :public std::logic_error
	{
	public:
		explicit bad_index(int ix, const std::string& s = "Index error in Sales object\n");
		int bi_val()const { return bi; }
		virtual ~bad_index()throw() {}

	private:
		int bi;
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year()const { return year; }
	virtual double operator[](int i)const;
	virtual double& operator[](int i);

private:
	double gross[MONTHS];
	int year;
};

class LabeledSales :public Sales
{
public:
	class nbad_index :public Sales::bad_index
	{
	public:
		nbad_index(const std::string& lb, int ix, const std::string& s = "Index error in LabeledSales object\n");
		const std::string& label_val()const { return lbl; }
		virtual ~nbad_index() throw() {}

	private:
		std::string lbl;
	};
	explicit LabeledSales(const std::string& lb = "none", int yy = 0);
	LabeledSales(const std::string& lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() {}
	const std::string& Label()const { return label; }
	virtual double operator[](int i)const;
	virtual double& operator[](int i);

private:
	std::string label;
};
