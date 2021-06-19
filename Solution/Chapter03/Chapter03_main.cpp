#include<iostream>
#include<climits>
#include<cfloat>
#include "Chapter03_main.h"

using namespace std;

int main()
{
	//sizeofBaseType();
	//displayFloatAndDouble();
	//displayFloatAndDoubleCalc();
	divideCalc();
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

void displayFloatAndDouble()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub=" << tub << endl;
	cout << "tub * million=" << tub * million << endl;
	cout << "10 * tub * million=" << 10 * tub * million << endl;
	cout << "mint=" << mint << endl;
	cout << "mint*million=" << mint * million << endl;
}

void displayFloatAndDoubleCalc()
{
	float a = 2.34e+22f;
	float b = a + 1.0f;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "b-a=" << b - a << endl;
}

void divideCalc()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Integer division: 9/5=" << 9 / 5 << endl;
	cout << "Floating-point division:9.0/5.0=" << 9.0 / 5.0 << endl;
	cout << "Mixed division:9.0/5=" << 9.0/5 << endl;
	cout << "Double constants:1e7/9.0=" << 1.e7 / 9.0 << endl;
	cout << "Float constants:1e7f/9.0f=" << 1.e7f / 9.0f << endl;
}
