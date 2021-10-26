#include"Chapter09_main.h"

int mainTemp()
{
	//staticBase();
	//autoBase();
	return 0;
}

void oil(int x)
{
	int texas = 5;

	cout << "In oil(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In oil(), x = " << x << ", &x = ";
	cout << &x << endl;
	{
		int texas = 113;
		cout << "In block, texas = " << texas;
		cout << ", &texas = " << &texas << endl;
		cout << "In block, x = " << x << ", &x = ";
		cout << &x << endl;
	}
	cout << "Post-block texas = " << texas;
	cout << ", &texas = " << &texas << endl;
}

void autoBase()
{
	int texas = 31;
	int year = 2011;
	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;
	oil(texas);
	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;
}

void staticBase()
{
	char input[ArSize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strCount(input);
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArSize);
	}
	cout << "Bye\n";
}

void strCount(const char* str)
{
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;
	cout << count << " character\n";
	cout << total << " character total\n";
}

extern "C" void spiff(int);
extern "C++" void spaff(int);

struct where { double x; double y; double z; };
where* one = new where{ 2.5,5.3,7.2 };
int* ar = new int[4]{ 2,4,6,7 };

int* pin = new int{};
double* pdo = new double{ 99.99 };
