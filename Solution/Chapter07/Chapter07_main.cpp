#include"Chapter07_main.h"

int main()
{
	arrFun4();
	//arrFun3();
	//arrFun2();
	//arrFun1();
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

int sum_arr(int* arr, int n)// int *arr = int arr[]
{
	int total = 0;
	std::cout << arr << " = arr, " << sizeof arr << " = sizeOf arr\n";
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total;
}

const int ArSize = 8;
void arrFun1()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten:" << sum << "\n";
}

void arrFun2()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	cout << cookies << " = array address, " << sizeof cookies << " = sizeof cookies\n";
	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten:" << sum << endl;
	sum = sum_arr(cookies, 3);
	cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, 4);
	cout << "Last four eater ate " << sum << " cookies.\n";
	sum = sum_arr(&cookies[6], 2);
	cout << "Last two eater ate " << sum << " cookies.\n";
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Property #" << i + 1 << ":$";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}

void arrFun3()
{
	using namespace std;
	const int Max = 5;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor:";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number:";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
}

int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;
	for (pt = begin; pt != end; pt++)
		total += *pt;
	return total;
}

void arrFun4()
{
	using namespace std;
	const int ArSize = 8;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Total cookies eaten:" << sum << " cookies.\n";
	sum = sum_arr(cookies, cookies + 3);
	cout << "First cookies eaten:" << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "Last four eater ate " << sum << " cookies.\n";
}