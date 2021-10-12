#include"Chapter08_main.h"

int main()
{
	strtRef();
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
