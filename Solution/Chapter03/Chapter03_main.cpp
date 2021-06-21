#include<iostream>
#include<climits>
#include<cfloat>
#include<math.h>
#include "Chapter03_main.h"

#define PI acos(-1)

using namespace std;

int main()
{
	//sizeofBaseType();
	//displayFloatAndDouble();
	//displayFloatAndDoubleCalc();
	//divideCalc();
	//modulusCalc();
	//conversionType();
	//conversionTypeOfCpp11();
	//conversionTypeCast();
	//PrecisionConversion();
	DoubleToInt();

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
	float tub = 10.0f / 3.0f;
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
	cout << "Mixed division:9.0/5=" << 9.0 / 5 << endl;
	cout << "Double constants:1e7/9.0=" << 1.e7 / 9.0 << endl;
	cout << "Float constants:1e7f/9.0f=" << 1.e7f / 9.0f << endl;
}

void modulusCalc()
{
	const int perLbsStn = 14;
	int lbs;

	cout << "Enter your weight in pounds:";
	cin >> lbs;
	int stone = lbs / perLbsStn;
	int pounds = lbs % perLbsStn;
	cout << "stone:" << stone << "\npounds:" << pounds << endl;
}

void conversionType()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess(3.1415f);
	int debt = 7.2E12;

	cout << "tree:" << tree << endl;
	cout << "guess:" << guess << endl;
	cout << "debt:" << debt << endl;
}

void conversionTypeOfCpp11()
{
	const int code = 66;
	int x = 66;
	//char c1{ 31325 };//not allow
	char c2 = { 66 };
	char c3{ code };
	//char c4 = { x };//not allow
	x = 31325;
	char c5 = x;

	//cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
	cout << "c3:" << c3 << endl;
	//cout << "c4:" << c4 << endl;
	cout << "c5:" << c5 << endl;
}

void conversionTypeCast()
{
	int auks, bats, coots;

	auks = 19.99 + 11.99;//31.98->31

	bats = (int)19.99 + (int)11.99;//19+11->30
	coots = int(19.99) + int(11.99);//ditto

	cout << "auks:" << auks << ends << "bats:" << bats << ends << "coots:" << coots << endl;

	char ch = 'Z';
	cout << "ch:" << ch << ends << "int(ch):" << int(ch) << ends << "static_cast<int>:" << static_cast<int>(ch) << endl;
}

void PrecisionConversion()
{
	cout.setf(ios_base::fixed, ios::floatfield);
	cout << LONG_MAX << endl;
	float a = LONG_MAX;
	cout << a << endl;//ÓÐÎó²î
	double b = LONG_MAX;
	cout << b << endl;//ÎÞÎó²î

	cout << LLONG_MAX << endl;
	float c = LLONG_MAX;
	cout << c << endl;//ÓÐÎó²î
	double d = LLONG_MAX;
	cout << d << endl;//ÓÐÎó²î
}

void DoubleToInt()
{
	double x1 = 1.999999;
	double x2 = 8.999999;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "x1:" << double(x1) << ends << "x2:" << double(x2) << endl;
	int a = int(x1) + int(x2);
	cout << "a:" << a << endl;
	int b = x1 + x2;
	cout << "b:" << b << endl;
}
