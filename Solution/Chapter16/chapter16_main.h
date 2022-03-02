#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;

void str1();

void str1()
{
	string one("Lottery Winner!");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += "Oops";
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!\n";
	string six(alls + 6, alls + 10);
	cout << six << ",";
	string seven(&five[6], &five[10]);
	cout << seven << "...\n";
	string eight(four, 7, 16);
	cout << eight << " in motion!" << endl;
}

void strfile();

void strfile()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "Can't open file.Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ":" << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
}