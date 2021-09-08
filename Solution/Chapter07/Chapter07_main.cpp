#include"Chapter07_main.h"

int main()
{
	protos();
	//Calling();
	return 0;
}

void Simple()
{
	using namespace std;
	cout << "I'm but a simple function.\n";
}

void Calling()
{
	using namespace std;
	cout << "Calling() will call the simple() function:\n";
	Simple();
	cout << "Finish calling!\n";
}

void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << "Cheers!";
	cout << endl;
}

double cube(double x)
{
	return x * x * x;
}

void protos()
{
	using namespace std;
	cheers(5);
	cout << "Give me a number:";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "A " << side << "-foot cube has a volume of " << volume << " cubic feet.\n";
	cheers(cube(2));
}
