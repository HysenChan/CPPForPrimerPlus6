#include<iostream>
#include<climits>
#include "Chapter03_main.h"

using namespace std;

int main()
{
	sizeofBaseType();
	return 0;
}

void sizeofBaseType()
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "bytes:" << endl;
	cout << "int:" << sizeof(int) << endl;
	cout << "short:" << sizeof(short) << endl;
	cout << "long:" << sizeof(long) << endl;
	cout << "long long:" << sizeof(long long) << endl;
	cout << endl;

	cout << "place holder:" << endl;
	cout << "int:" << n_int << endl;
	cout << "short:" << n_short << endl;
	cout << "long:" << n_long << endl;
	cout << "long long:" << n_llong << endl;
}