#include<iostream>
#include"Chapter04_main.h"

using namespace std;

int main()
{
	//ArrayOne();
	//StringBase();
	InStr1Cpp();
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

	cout << "\nSize of yams array = " << sizeof yams << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";
}

void StringBase()
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "B:	Hi,I'm " << name2 << ",What's your name?\n";
	cin >> name1;
	cout << "A:	My name is " << name1 << ",has " << strlen(name1) << " letters and is stored in an array of " << sizeof(name1) << " bytes.\n";
	cout << "B:	Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';
	cout << "A:	Here are the first 3 character of my name:" << name2 << endl;
}

void InStr1Cpp()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert << " for you," << name<<".\n";
}
