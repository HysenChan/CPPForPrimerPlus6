#include"Chapter07_main.h"

int main()
{
	const int ArrSize = 3;
	int arr[ArrSize];
	//review03(arr, ArrSize, 1);
	//arfupt();
	//fun_ptr();
	//ruler();
	//recur();
	//arrobj();
	//topFive();
	//atrctFun();
	//travel();
	//strgback();
	//strgFun();
	//PointerAndStr();
	//PointerAndConst();
	//arrFun4();
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

void PointerAndConst()
{
	using namespace std;
	//valid
	int age = 39;
	const int* pt = &age;
	//*pt+=1; invalid
	age = 20;

	//valid
	const float g_earth = 9.80;
	const float* pe = &g_earth;

	const float g_moon = 1.63;
	//float* pm = &g_moon; invalid

	//valid
	int* pd = &age;
	const int* pt1 = pd;

	//valid
	int gorp = 16;
	int chips = 12;
	const int* p_snack = &gorp;

	p_snack = &chips;

	int* const p_snack1 = &gorp;
	*p_snack1 = 20;
}

void PointerAndStr()
{
	using namespace std;
	char ghost[15] = "galloping";
	const char* str = "galumphing";
	int n1 = strlen(ghost);
	int n2 = strlen(str);
	int n3 = strlen("gamboling");
	cout << "n1:" << n1 << endl;
	cout << "n2:" << n2 << endl;
	cout << "n3:" << n3 << endl;
}

unsigned int c_in_str(const char* str, char ch)
{
	unsigned int count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return count;
}

void strgFun()
{
	using namespace std;
	char mmm[15] = "minimum maxmum";

	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');

	cout << "ms:" << ms << endl;
	cout << "us:" << us << endl;
}

char* buildstr(char c, int n)
{
	char* pstr = new char[n + 1];
	pstr[n] = '\0';
	while (n-- > 0)
		pstr[n] = c;
	return pstr;
}

void strgback()
{
	using namespace std;
	int times;
	char ch;

	cout << "Enter a character:";
	cin >> ch;
	cout << "Enter a integer:";
	cin >> times;
	char* ps = buildstr(ch, times);
	cout << ps << endl;
	delete[] ps;
	ps = buildstr('+', 20);
	cout << ps << "-DONE-" << ps << endl;
	delete[] ps;
}

const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;

	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
	return total;
}

void show_time(travel_time t)
{
	using namespace std;
	cout << t.hours << " hours, " << t.mins << " minutes\n";
}

void travel()
{
	using namespace std;
	travel_time day1 = { 5,45 };
	travel_time day2 = { 4,55 };

	travel_time trip = sum(day1, day2);
	cout << "Two-day total:";
	show_time(trip);

	travel_time day3 = { 4,32 };
	cout << "Three-day total:";
	show_time(sum(trip, day3));
}

void rect_to_polar(const rect* xyPos, polar* pda)
{
	using namespace std;

	pda->distance = sqrt(xyPos->x * xyPos->x + xyPos->y * xyPos->y);
	pda->angle = atan2(xyPos->y, xyPos->x);
}

void show_polar(const polar* daPos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "distance = " << daPos->distance << endl;
	cout << "angle = " << daPos->angle * Rad_to_deg << " degress.\n";
}

void atrctFun()
{
	using namespace std;
	rect rPlace;
	polar pPlace;

	cout << "Enter the x and y values:";
	while (cin >> rPlace.x >> rPlace.y)
	{
		rect_to_polar(&rPlace, &pPlace);
		show_polar(&pPlace);
		cout << "Next two numbers (any character to quit):";
	}
	cout << "Done.\n";
}

void display(const std::string sa[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << i + 1 << ":" << sa[i] << std::endl;
}

void topFive()
{
	using namespace std;
	const int SIZE = 5;
	string list[SIZE];
	cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ":";
		getline(cin, list[i]);
	}

	cout << "Your list:\n";
	display(list, SIZE);
}

void fill(std::array<double, Seasons>* pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses:";
		cin >> (*pa)[i];
	}
}

void show(std::array<double, Seasons> da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ":$" << da[i] << endl;
		total += da[i];
	}
	cout << "Total expenses:$" << total << endl;
}

void arrobj()
{
	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);
}

void countdown(int n)
{
	using namespace std;
	cout << "Counting down ... " << n << endl;
	if (n > 0)
		countdown(n - 1);
	cout << n << ": Kaboom!\n";
}

void recur()
{
	countdown(4);
}

void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}

void ruler()
{
	const int Len = 66;
	const int Divs = 6;

	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	for (int i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';
	}
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.004 * lns * lns;
}

void estimat(int lines, double(*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
}

void fun_ptr()
{
	using namespace std;
	int code;
	cout << "How many lines of code do you need?";
	cin >> code;
	cout << "Here's Besty's estimate:\n";
	estimat(code, betsy);
	cout << "Here's Pam's estimate:\n";
	estimat(code, pam);
}

const double* f1(const double ar[], int n)
{
	return ar;
}

const double* f2(const double ar[], int)
{
	return ar + 1;
}

const double* f3(const double* ar, int)
{
	return ar + 2;
}

void arfupt()
{
	using namespace std;
	typedef const double* (*p_fun)(const double*, int);
	double av[3] = { 1112.3,1542.6,2227.9 };

	p_fun p1 = f1;
	//const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;

	cout << "Using pointers to function:\n";
	cout << " Address Value\n";
	cout << (*p1)(av, 3) << ":" << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ":" << *p2(av, 3) << endl;

	p_fun pa[3] = { f1,f2,f3 };
	//const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
	auto pb = pa;
	cout << "\nmethod 1 of pa: Using an array of pointers to functions:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ":" << *pa[i](av, 3) << endl;
	cout << "\nmethod 2 of pa: Using a pointer to a pointer to a functions:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << (*pa[i])(av, 3) << ":" << *(*pa[i])(av, 3) << endl;
	cout << "\npb: Using a pointer to a pointer to a functions:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ":" << *pb[i](av, 3) << endl;

	cout << "\npc: Using a pointer to an array of pointers:\n";
	cout << " Address Value\n";
	p_fun(*pc)[3] = &pa;
	//auto pc = &pa;

	cout << (*pc)[0](av, 3) << ":" << *(*pc)[0](av, 3) << endl;


	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ":" << *pdb << endl;
	cout << (*(*pd)[2])(av, 3) << ":" << *(*(*pd)[2])(av, 3) << endl;
}

void review03(int ar[], int len, int value)
{
	using namespace std;
	for (int i = 0; i < len; i++)
		ar[i] = value;
	for (int i = 0; i < len; i++)
		cout << i << ":" << ar[i] << endl;
}
