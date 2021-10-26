#include"review.h"

int main()
{
	Review03();
	return 0;
}

void Review03()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x;
	cout << "Enter value:";
	while (!(cin >> x))
	{
		cout << "Bad input.Please enter a number:";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cout << "Value = " << x << endl;
}
