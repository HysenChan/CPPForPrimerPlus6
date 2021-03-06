#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;

#define SQUARE(X) ((X)*(X))
inline double square(double x) { return x * x; }
void inlineBase();

void firstRef();
void sceRef();
void tempRef();

void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);
void displaySwapResult(int a, int b);
void swaps();

double valueCube(double a);
double refCube(const double& ra);
void cubes();

void rightRef();

struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);
void strtRef();

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);
const string& version3(string& s1, const string& s2);
void strquote();

const int LIMIT = 5;
void file_it(ostream& os, double fo, const double fe[]);
void fileFunc();

const int ArSize = 80;
char* left(const char* str, int n = 1);
void left();

void stove(double& r1);
void stove(const double& r2);
void stove(double&& r3);
void stoveTest();

unsigned long left(unsigned long num, unsigned ct);
void leftover();

template<typename T>
void Swap(T& a, T& b);
template<typename T>
void displaySwap(T& i, T& j);
void funtemp();

template<typename T>
inline void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
inline void displaySwap(T& i, T& j)
{
	cout << "i,j = " << i << "," << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i,j = " << i << ", " << j << ".\n";
}

template<typename T>
void Swap(T* a, T* b, int n);
void Show(int a[]);
const int Lim = 8;
void twotemps();

template<typename T>
inline void Swap(T* a, T* b, int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

struct job
{
	char name[40];
	double salary;
	int floor;
};

template<> void Swap<job>(job& j1, job& j2);//????Swap()????????job??????????????
template<> inline void Swap(job& j1, job& j2)
{
	double t1;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	int t2;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j);
void twoSwap();

template<typename T>
void ShowArray(T arr[], int n);

template<typename T>
void ShowArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

void tempTempOver();

template<typename T>
inline void ShowArray(T arr[], int n)
{
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
template<typename T>
inline void ShowArray(T* arr[], int n)
{
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}

template<class T>
T lesser(T a, T b);

template<class T>
inline T lesser(T a, T b)
{
	return a < b ? a : b;
}

int lesser(int a, int b);
void choices();

template<class T1, class T2>
void ft(T1 x, T2 y)
{
	//? type ? xpy = x + y;
	decltype(x + y) xpy = x + y;
}

//????????
double h(int x, float y);
auto h(int x, float y)->double;

template<class T1, class T2>
auto gt(T1 x, T2  y)->decltype(x + y)
{
	return x + y;
}

//??????Review
//Review04
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void showBox(const box* b);
float calcVolume(box& b);
void Review04();

//Review07
template<class T>
T maxValue(T t1, T t2);

template<class T>
inline T maxValue(T t1, T t2)//T maxValue(const T& t1, const T& t2)
{
	return t1 > t2 ? t1 : t2;
}

//Review08
template<class box> box maxBox(box& b1, box& b2)
{
	b1.volume = b1.height * b1.length * b1.width;
	b2.volume = b2.height * b2.length * b2.width;
	return b1.volume > b2.volume ? b1 : b2;
}
void Review08();

//????????
//Practice01
void print(char* str, int n = 0);
void Practice01();

//Practice02
struct CandyBar
{
	char name[30];
	float weight;
	int calories;
};
void SetCandyBarValue(CandyBar& cb, const char* str = "Millennium Munch", const double w = 2.85, const int c = 350);
void Practice02();

//Practice03
string strToUpper(std::string& str);
void Practice03();

//Practice04
struct stringy
{
	char* str;
	int ct;
};
void set(stringy& sy, const char* str);
void show(const stringy& sy, const int n = 1);
void show(const string& str, const int n = 1);
void Practice04();

//Practice05
const int Limit = 5;
template<typename T>
T max5(T arr[], const int& Limit);

template<typename T>
inline T max5(T arr[], const int& Limit)
{
	T max;
	max = arr[0];
	for (int i = 1; i < Limit; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void Practice05();

//Practice06
template<typename T>
T maxn(T arr[], const int length);
template<typename T>
inline T maxn(T arr[], const int length)
{
	T max = 0;
	for (int i = 0; i < length; i++)
		max = max > arr[i] ? max : arr[i];
	return max;
}
template<> char* maxn(char* arr[], int n);
template<>
inline char* maxn(char* arr[], int n)
{
	int j = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < strlen(arr[i]))
		{
			max = strlen(arr[i]);
			j = i;
		}
	}
	char* address = arr[j];
	return address;
}
void Practice06();

//Practice07
template<typename T> T SumArray(T arr[], int n);
template<typename T> T SumArray(T* arr[], int n);
template<typename T>
inline T SumArray(T arr[], int n)
{
	cout << "Template A\n";
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}
template<typename T>
inline T SumArray(T* arr[], int n)
{
	cout << "Template B\n";
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}
void Practice07();