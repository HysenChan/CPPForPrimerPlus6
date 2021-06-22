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
	//DoubleToInt();
	//InchToFoot();
	//CalcBMI();
	//CalcDegress();
	//SecToSpecific();
	//PrecentOfPerson();
	//EuropeStyleOil();
	UsStypeOil();

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
	cout << a << endl;//有误差
	double b = LONG_MAX;
	cout << b << endl;//无误差

	cout << LLONG_MAX << endl;
	float c = LLONG_MAX;
	cout << c << endl;//有误差
	double d = LLONG_MAX;
	cout << d << endl;//有误差
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

void InchToFoot()
{
	const float one_inch_for_foot = 1.0f / 12.0f;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Please enter your height by inch:____\b\b\b\b";
	int inch;
	cin >> inch;
	float foot = inch * one_inch_for_foot;
	cout << "Height inch is:" << inch << endl;
	cout << "Height foot is:" << foot << endl;
}

void CalcBMI()
{
	const int one_foot_for_inch = 12;
	const float one_foot_for_meter = 0.0254f;
	const float one_kg_for_pounds = 2.2f;
	int foot, inch;
	float pounds;
	cout << "Please enter your foot and inch:" << ends;
	cin >> foot;
	cin >> inch;
	int convertInch = foot * one_foot_for_inch + inch;
	float height = convertInch * one_foot_for_meter;
	cout << "Your height is:" << height << endl;
	cout << "Please enter your pounds:" << ends;
	cin >> pounds;
	float weight = pounds / one_kg_for_pounds;
	cout << "Your weight is:" << weight << endl;
	double bmi = pow(weight / height, 2);
	cout << "Your BMI is:" << bmi << endl;
}

void CalcDegress()
{
	const int one_degress_for_min = 60;
	const int one_min_for_sec = 60;
	int degrees, minutes, seconds;
	cout << "Enter a latitude in degress, minutes, and seconds:" << endl;
	cout << "First, enter the degrees:" << ends;
	cin >> degrees;
	cout << "Next, enter the minutes of arc:" << ends;
	cin >> minutes;
	cout << "Finally, enter the seconds of arc:" << ends;
	cin >> seconds;
	float secToMin = float(seconds) / one_min_for_sec;
	float minToDegrees = secToMin / one_degress_for_min + float(minutes) / one_degress_for_min;
	float finallDegrees = float(degrees) + minToDegrees;
	cout << degrees << " degrees , " << minutes << " minutes , " << seconds << " seconds = " << finallDegrees << " degrees." << endl;
}

void SecToSpecific()
{
	const int one_day_for_hour = 24;//1day->24h
	const int one_hour_for_min = 60;//1hour->60min
	const int one_min_for_sec = 60;//1min->60sec
	const int oneDaySec = one_day_for_hour * one_hour_for_min * one_min_for_sec;//1day->86400sec

	cout << "Enter the number of seconds:";
	long inputSec;
	cin >> inputSec;

	int seconds = inputSec % one_min_for_sec;//秒数取余
	int minutes = (inputSec / one_min_for_sec) % one_min_for_sec;//转换成分钟，分钟取余
	int hours = (inputSec / one_min_for_sec / one_hour_for_min) % one_day_for_hour;//转换成小时，小时取余
	int days = inputSec / oneDaySec;//总秒数/一天总秒数
	printf("%ld seconds = %d days, %d hours, %d minutes, %d seconds:", inputSec, days, hours, minutes, seconds);
}

void PrecentOfPerson()
{
	long long worldPerson;
	long long chinaPerson;
	cout << "Enter the world's population:";
	cin >> worldPerson;
	cout << "Enter the china's population:";
	cin >> chinaPerson;

	double precent = double(chinaPerson) / worldPerson;
	precent *= 100;
	cout << "The population of the china is " << precent << "% of the world population.";
}

void EuropeStyleOil()
{
	//输入英里和加仑
	float mile, gallon;
	cout << "Please enter mile:";
	cin >> mile;
	cout << "Please enter gallon:";
	cin >> gallon;
	//欧洲风格
	cout << "one gallon run:" << mile / gallon << endl;//1加仑跑的距离

	//输入公里和升
	float km, liter;
	cout << "Please enter km:";
	cin >> km;
	cout << "Please enter liter:";
	cin >> liter;
	cout << "one hundred km consume " << 100 * (liter / km) << "L." << endl;//欧洲风格100km耗油量?L
}

void UsStypeOil()
{
	const float one_hundred_km_for_mile = 62.14;
	const float one_gallon_for_liter = 3.875;
	const float one_hundred_km_for_liter = 12.4;

	//输入耗油量
	float liter;
	cout << "Please enter consume liter:";
	cin >> liter;
	cout << "use gallon:" << liter / one_gallon_for_liter << endl;
	//美国风格
	cout << "one gallon can run " << one_hundred_km_for_mile / (one_hundred_km_for_liter / one_gallon_for_liter) << " mile." << endl;//每加仑？英里
	cout << "one mile consume gallon " << one_hundred_km_for_liter / one_gallon_for_liter / one_hundred_km_for_mile << " L." << endl;//每英里？加仑
}
