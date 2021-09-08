#include"Chapter07_main.h"

int main()
{
	arrFun1();
	//lotto();
	//twoArg();
	//protos();
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

void n_chars(char c, int n)
{
	while (n-- > 0)
		std::cout << c;
}

void twoArg()
{
	using namespace std;
	int times;
	char ch;

	cout << "Enter a character:";
	cin >> ch;
	while (ch != 'q')
	{
		cout << "Enter an integer:";
		cin >> times;
		n_chars(ch, times);
		cout << "\nEnter another character or press the q-key to quit:";
		cin >> ch;
	}
	cout << "The value of times is " << times << ".\n";
	cout << "Bye\n";
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}

void lotto()
{
	using namespace std;
	double total, choices;
	cout << "Enter the total number of choices on the game card and the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices);
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit):";
	}
	cout << "bye\n";
}

int sum_arr(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total;
}

void arrFun1()
{
	const int ArSize = 8;
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten:" << sum << "\n";
}
