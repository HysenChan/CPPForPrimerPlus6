#include"review.h"
//void Review03()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//	double x;
//	cout << "Enter value:";
//	while (!(cin >> x))
//	{
//		cout << "Bad input.Please enter a number:";
//		cin.clear();
//		while (cin.get() != '\n')
//			continue;
//	}
//	cout << "Value = " << x << endl;
//}

using namespace std;
void other1();
void another1();
int x = 10;
int y;
void Review06()
{
	cout << x << endl;
	{
		int x = 4;
		cout << x << endl;
		cout << y << endl;
	}
	other1();
	another1();
}

void other1()
{
	int y = 1;
	cout << "Other: " << x << "," << y << endl;
}

int main_review()
{
	Review06();
	return 0;
}