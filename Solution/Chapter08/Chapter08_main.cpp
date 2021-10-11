#include"Chapter08_main.h"

int main()
{
	tempRef();
	//sceRef();
	//firstRef();
	//inlineBase();
	return 0;
}

void inlineBase()
{
	using namespace std;
	double a, b, d;
	double c = 13.0;

	//a = square(5.0);
	a = SQUARE(5.0);
	//b = square(4.5 + 7.5);
	b = SQUARE(4.5 + 7.5);
	cout << "a = " << a << ",b = " << b << endl;
	cout << "c = " << c;
	cout << ",c squared = " << square(c++) << endl;
	cout << "Now c = " << c << "\n";
	d = SQUARE(c++);
	cout << "d:" << c << ",d square:" << d << endl;
}

void firstRef()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;
}

void sceRef()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies address = " << &bunnies;
	cout << ", rodents address = " << &rodents << endl;
}

void tempRef()
{
	//只改动了指针的指向，无法改变引用的指向（即：引用初始化指向谁就固定是谁)
	using namespace std;
	int rats = 101;
	int* pt = &rats;
	int& rodents = *pt;
	int bunnies = 50;
	cout << "*pt:" << *pt << ",pt:" << pt << endl;
	pt = &bunnies;
	cout << "*pt:" << *pt << ",pt:" << pt << endl;
	cout << "rodents:" << rodents << ",&rodents:" << &rodents << endl;
	cout << "bunnies:" << bunnies << ",&bunnies:" << &bunnies << endl;
}
