#include"Chapter08_main.h"

int main()
{
	inlineBase();
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
