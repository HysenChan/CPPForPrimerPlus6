#include<iostream>
#include"coordin.h"

using namespace std;

int main()
{
	rect rPlace;
	polar pPlace;

	cout << "Enter the x and y values:";
	while (cin >> rPlace.x >> rPlace.y)
	{
		pPlace = rect_to_polar(rPlace);
		show_polar(pPlace);
		cout << "Next two numbers (q to quit):";
	}
	cout << "Bye!\n";
	return 0;
}