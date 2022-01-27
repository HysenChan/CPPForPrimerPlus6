#include"tv.h"
#include"error1.h"
#include"rtti1.h"
#include<iostream>
using namespace std;

void use_tv();

void error1();

double hmean(double a, double b);
double gmean(double a, double b);

void error5();

void newexcp();

void use_sales();

void rtti1();

struct Big
{
	double stuff[20000];
};

int main()
{
	rtti1();
	//use_sales();
	//newexcp();
	//error5();
	//error1();
	//use_tv();
	return 0;
}

void use_tv()
{
	Tv s42;
	cout << "Initial settings for 42\"TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.voldown(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();
}

void error1()
{
	double x, y, z;

	std::cout << "Enter two numbers:";
	while (std::cin >> x >> y)
	{
		//error1
		/*z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;*/

		//error2
		/*if (hmean(x, y, &z))
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative of the other - try again.\n";*/

			//error3
		try
		{
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << std::endl;
		}
		catch (bad_hmean& bg)
		{
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "values used:" << hg.v1 << "," << hg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
		/*std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		std::cout << "Enter next set of numbers < q to quit >:";*/
	}
	std::cout << "Bye!\n";
}

inline void error5()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter two numbers:";
		while (cin >> x >> y)
		{
			try
			{
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "Values used:" << hg.v1 << "," << hg.v2 << endl;
				cout << "Sorry,you don't get to play any more.\n";
				break;
			}
		}
		d1.show();
	}
	cout << "Bye!\n";
	cin.get();
	cin.get();
}

void newexcp()
{
	Big* pb;
	try
	{
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[10000];
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
}

void use_sales()
{
	double vals1[12] =
	{
		1220,1100,1122,2212,1232,2334,
		2884,2393,3302,2922,3002,3544,
	};

	double vals2[12] =
	{
		12,11,22,21,32,34,
		28,29,33,29,32,35,
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company:" << bad.label_val() << endl;
		cout << "bad index:" << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index:" << bad.bi_val() << endl;

		cout << "\nNext try block:\n";
		try
		{
			sales2[2] = 37.5;
			sales1[20] = 23345;
			cout << "End of try block 2.\n";
		}
		catch (LabeledSales::nbad_index& bad)
		{
			cout << bad.what();
			cout << "Company:" << bad.label_val() << endl;
			cout << "bad index:" << bad.bi_val() << endl;
		}
		catch (Sales::bad_index& bad)
		{
			cout << bad.what();
			cout << "bad index:" << bad.bi_val() << endl;
		}
		cout << "done\n";
	}
}

Grand* GetOne()
{
	Grand* p{};
	switch (std::rand() % 3)
	{
	case 0:p = new Grand(std::rand() % 100);
		break;
	case 1:p = new Superb(std::rand() % 100);
		break;
	case 2:p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	}
	return p;
}

void rtti1()
{
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
	}
}
