#include<iostream>
#include"Chapter04_main.h"

using namespace std;

int main()
{
	ArrayOne();
	return 0;
}

void ArrayOne()
{
	int yams[3];
	yams[0] = 1;
	yams[1] = 2;
	yams[2] = 3;

	int yamcosts[3] = { 20,30,5 };

	cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs " << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";
	int elementNum = sizeof yamcosts / sizeof(int);
	cout << "The element num of yamcosts is " << elementNum << ".\n";

	cout << "\nSize of yams array = " << sizeof yams<<" bytes.\n";
	cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";
}
