#include"tv.h"
#include"error1.h"
#include<iostream>
using namespace std;

void use_tv();

void error1();

double hmean(double a, double b);
double gmean(double a, double b);

void error5();

int main()
{
	error5();
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