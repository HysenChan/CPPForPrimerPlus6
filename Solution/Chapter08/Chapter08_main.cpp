#include"Chapter08_main.h"

int main()
{
	Practice07();
	//Practice06();
	//Practice05();
	//Practice04();
	//Practice03();
	//Practice02();
	//Practice01();
	//Review08();
	//Review04();
	//choices();
	//tempTempOver();
	//twoSwap();
	//twotemps();
	//funtemp();
	//leftover();
	//stoveTest();
	//left();
	//fileFunc();
	//strquote();
	//strtRef();
	//rightRef();
	//cubes();
	//swaps();
	//tempRef();
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

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void displaySwapResult(int a, int b)
{
	using namespace std;
	cout << "---------------------\n";
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}

void swaps()
{
	using namespace std;
	int wallet1 = 1;
	int wallet2 = 2;
	swapr(wallet1, wallet2);
	displaySwapResult(wallet1, wallet2);

	wallet1 = 1;
	wallet2 = 2;
	swapp(&wallet1, &wallet2);
	displaySwapResult(wallet1, wallet2);

	wallet1 = 1;
	wallet2 = 2;
	swapv(wallet1, wallet2);
	displaySwapResult(wallet1, wallet2);
}

double valueCube(double a)
{
	a *= a * a;
	return a;
}

double refCube(const double& ra)
{
	return ra * ra * ra;
}

void cubes()
{
	using namespace std;
	double x = 3.0;

	cout << valueCube(x) << " = cube of " << x << endl;
	cout << refCube(x) << " = cube of " << x << endl;
}

void rightRef()
{
	double&& rref = std::sqrt(36.00);
	double j = 15.0;
	double&& jref = 2.0 * j + 18.5;
	std::cout << rref << std::ends << &rref << '\n';
	std::cout << jref << std::ends << &jref << '\n';
}

void display(const free_throws& ft)
{
	using std::cout;
	using std::endl;
	cout << "---------------\n";
	cout << "Name:" << ft.name << endl;
	cout << "Made:" << ft.made << endl;
	cout << "Attempts:" << ft.attempts << endl;
	cout << "Percent:" << ft.percent << endl;
}

void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}

void strtRef()
{
	free_throws one = { "A",13,14 };
	free_throws two = { "B",10,16 };
	free_throws three = { "C",7,9 };
	free_throws four = { "D",5,9 };
	free_throws five = { "E",6,14 };
	free_throws team = { "F",0,0 };

	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	dup = accumulate(team, five);
	std::cout << "Displaying team:\n";
	display(team);
	std::cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);

	accumulate(dup, five) = four;
	std::cout << "Displaying dup after ill_advised assignment:\n";
	display(dup);
}

string version1(const string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

void strquote()
{
	using namespace std;
	string input;
	string copy;
	string result;

	cout << "Enter a string:";
	getline(cin, input);
	copy = input;
	cout << "Your string as entered:" << input << endl;
	result = version1(input, "***");
	cout << "Your string enhanced:" << result << endl;
	cout << "Your original string:" << input << endl;

	result = version2(input, "###");
	cout << "Your string enhanced:" << result << endl;
	cout << "Your original string:" << input << endl;

	cout << "Resetting original string.\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "Your string enhanced:" << result << endl;
	cout << "Your original string:" << input << endl;
}

void file_it(ostream& os, double fo, const double fe[])
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os << "Focal length of objective:" << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "f.1. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < LIMIT; i++)
	{
		os.width(12);
		os << fe[i];
		os.widen(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}

void fileFunc()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ".Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your telescope objective in mm:";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + i << ":";
		cin >> eps[i];
	}
	file_it(fout, objective, eps);
	file_it(cout, objective, eps);
	cout << "Done.\n";
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}

void left()
{
	char sample[ArSize];
	cout << "Enter a string:\n";
	cin.get(sample, ArSize);
	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
}

void stove(double& r1)
{
	cout << "r1:" << r1 << endl;
}

void stove(const double& r2)
{
	cout << "r2:" << &r2 << endl;
}

void stove(double&& r3)
{
	cout << "r3:" << r3 << endl;
}

void stoveTest()
{
	double x = 55.5;
	const double y = 32.0;
	stove(x);
	stove(y);
	stove(x + y);
}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

void leftover()
{
	const char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;

	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}
}

void funtemp()
{
	int i = 10;
	int j = 20;
	displaySwap(i, j);

	double x = 24.5;
	double y = 81.7;
	displaySwap(x, y);
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}

void twotemps()
{
	int i = 10, j = 20;
	displaySwap(i, j);

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,7,2,0,1,9,6,9 };
	cout << "Original arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	Show(d1);
	Show(d2);
}

void Show(job& j)
{
	cout << j.name << ":$" << j.salary << " on floor " << j.floor << endl;
}

void twoSwap()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	displaySwap(i, j);

	job sue = { "Susan Yaffee",73000.60,7 };
	job sidney = { "Sidney Taffe",78060.72,9 };
	cout << "Befort job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
}

void tempTempOver()
{
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0},
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listring Mr.E's counts of things:\n";
	ShowArray(things, 6);
	cout << "Listring Mr.E's debts:\n";
	ShowArray(pd, 3);
}

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

void choices()
{
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;
	cout << lesser(x, y) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;
}

void showBox(const box* b)
{
	cout << "b.maker:" << b->maker << endl;
	cout << "b.height:" << b->height << endl;
	cout << "b.width:" << b->width << endl;
	cout << "b.length:" << b->length << endl;
	cout << "b.volume:" << b->volume << endl;
}

float calcVolume(box& b)
{
	b.volume = b.height * b.width * b.length;
	return b.volume;
}

void Review04()
{
	box* b = new box;
	*b = { "BOX", 10, 20, 30 };
	showBox(b);
	calcVolume(*b);
	cout << "-----------After calc volume:\n";
	showBox(b);
	delete b;
}

void Review08()
{
	box* b = new box[2];
	b[0] = { "b1",1,2,3 };
	b[1] = { "b2",2,3,4 };
	box tempB = maxBox(b[0], b[1]);
	showBox(&tempB);
	delete[] b;
}

void print(char* str, int n)
{
	static int flag = 0;
	flag++;
	cout << "flag:" << flag << endl;
	if (n == 0)
		cout << str << endl;
	else
	{
		for (int i = 0; i < flag; i++)
			cout << str << endl;
	}
	cout << endl;
	return;
}

void Practice01()
{
	char str[20] = "Hello World!";
	print(str);
	print(str, 5);
	print(str, 16);
	print(str);
}

void SetCandyBarValue(CandyBar& cb, const char* str, const double w, const int c)
{
	strcpy_s(cb.name, str);
	cb.weight = w;
	cb.calories = c;
	cout << "cb.name:" << cb.name << endl;
	cout << "cb.weight:" << cb.weight << endl;
	cout << "cb.calories:" << cb.calories << endl;
	cout << endl;
}

void Practice02()
{
	CandyBar* cb1 = new CandyBar[2];
	cb1[0] = { "cb1",30,2000 };
	SetCandyBarValue(cb1[0]);
	SetCandyBarValue(cb1[1], "cb2", 50, 1000);
	delete[]cb1;
}

string strToUpper(std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

void Practice03()
{
	cout << "Enter a string(q to quit):";
	string str;
	getline(cin, str);
	while (str != "q")
	{
		str = strToUpper(str);
		cout << str << endl;
		cout << "Next string (q to quit):";
		getline(cin, str);
	}
	cout << "Bye." << endl;
}

void set(stringy& sy, const char* str)
{
	sy.ct = strlen(str) + 1;
	sy.str = new char[sy.ct];
	strcpy_s(sy.str, sy.ct, str);
}

void show(const stringy& sy, const int n)
{
	for (int i = 0; i < n; i++)
		cout << "sy.str:" << sy.str << endl;
	cout << "sy.ct:" << sy.ct << endl;
}

void show(const string& str, const int n)
{
	for (int i = 0; i < n; i++)
		cout << "str:" << str << endl;
	cout << endl;
}

void Practice04()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

void Practice05()
{
	int intArr[5] = { 1,2,3,4,5 };
	double doubleArr[5] = { 1.1,2.2,3.3,4.4,5.5 };
	int max1 = max5(intArr, Limit);
	double max2 = max5(doubleArr, Limit);
	cout << "max1:" << max1 << endl;
	cout << "max2:" << max2 << endl;
}

void Practice06()
{
	int arr1[6] = { 1,2,3,4,5,6 };
	double arr2[4] = { 1.5,9.0,3.4,0.1 };
	int max1;
	double max2;
	max1 = maxn(arr1, 6);
	max2 = maxn(arr2, 4);
	const char* arr3[5] = { "one","two","three","four","five" };
	const char* max3;
	max3 = maxn(arr3, 5);
	cout << "max1:" << max1 << endl;
	cout << "max2:" << max2 << endl;
	cout << "max3:" << &max3 << endl;
	cout << "Bye!\n";
}

void Practice07()
{
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0},
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	int sum1 = SumArray(things, 6);
	cout << "Sum1:" << sum1 << endl;
	int sum2 = SumArray(pd, 3);
	cout << "Sum2:" << sum2 << endl;
}