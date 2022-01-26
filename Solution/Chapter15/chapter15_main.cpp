#include"tv.h"
#include"error1.h"
#include<iostream>
using namespace std;

void use_tv();

void error1();

int main()
{
	error1();
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
		/*z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;*/
		if (hmean(x, y, &z))
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative of the other - try again.\n";
		std::cout << "Enter next set of numbers < q to quit >:";
	}
	std::cout << "Bye!\n";
}
