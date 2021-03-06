#pragma once

#include<iostream>
#include<cmath>
#include<string>
#include<array>
#include<map>
#include<vector>

//Calling
void Simple();
void Calling();

//Protos
void cheers(int);
double cube(double x);
void protos();

void n_chars(char, int);
void twoArg();

long double probability(unsigned numbers, unsigned picks);
void lotto();

int sum_arr(int* arr, int n);
void arrFun1();

void arrFun2();

double* fill_array(double* ar, double* limit);
void show_array(const double* ar, double* end);
void revalue(double r, double* ar, double* end);
void arrFun3();

int sum_arr(const int* begin, const int* end);
void arrFun4();

void PointerAndConst();
void PointerAndStr();

unsigned int c_in_str(const char* str, char ch);
void strgFun();

char* buildstr(char c, int n);
void strgback();

struct travel_time
{
	int hours;
	int mins;
};
travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);
void travel();

struct polar
{
	double distance;
	double angle;
};
struct rect
{
	double x;
	double y;
};
void rect_to_polar(const rect* xyPos, polar* pda);
void show_polar(const polar* daPos);
void atrctFun();

void display(const std::string sa[], int n);
void topFive();

const int Seasons = 4;
const std::array<std::string, Seasons> Snames = { "Spring","Summer","Fall","Winter" };
void fill(std::array<double, Seasons>* pa);
void show(std::array<double, Seasons> da);
void arrobj();

void countdown(int n);
void recur();

void subdivide(char ar[], int low, int high, int level);
void ruler();

double betsy(int);
double pam(int);
void estimat(int lines, double (*pf)(int));
void fun_ptr();

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);
void arfupt();

//Chapter07 ReviewTest
//Review02
struct boss
{
	char name;
	char age;
};
void igor();
float tofu(int);
double mpg(double, double);
long summation(long[], int length);
double doctor(const char*);
void ofcourse(boss);
char plot(std::map<std::string, std::vector<int>>);

//Review03
void review03(int[], int len, int);

//Review04
void review04(int* begin, int* end, int value);

//Review05
double review05(const double*, int len);

//Review08
int replace(char* str, char c1, char c2);

//Review09
void review09();

//Review10
struct glitz
{
	int age;
	std::string name;
};

void review10(const glitz* g);

//Review11
int review11(int (*pf)(const char*));

//Review12
struct applicant
{
	char name[30];
	int credit_ratings[3];
};

void displayByValue(applicant app);
void displayByPointer(applicant* app);
void displayByReference(applicant& app);
void review12();

//Review13
void f11(applicant* a);
const char* f12(const applicant* a1, const applicant* a2);
void review13();

//Practice01
double calcHarmonic(int x, int y);
void Practice01();

//Practice02
const int Max = 10;
int inputScore(double arr[], int limit);
void displayScore(const double arr[], int n);
double calcAverage(double arr[], int n);
void Practice02();

//Practice03
struct box
{
	char maxker[40];
	float height;
	float width;
	float length;
	float volume;
};
void showBoxByValue(box);
void calcVolumeByReference(box&);
void Practice03();

//Practice04
const int areaRange1 = 47;
const int areaRange2 = 27;
const int chooiceRange1 = 5;
const int chooiceRange2 = 1;
double calcLotteryTicket(int area1, int area2, int chooice1, int chooice2);
void Practice04();

//Practice05
int factorial(int num);
void Practice05();

//Practice06
int Fill_array(double[], int len);
void Show_array(const double*, int len);
void Reverse_arr(double*, int len);
void Practice06();

//Practice08
struct Cost
{
	double arr[Seasons];
};
const char* seasonNames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
void fillPractice08(double season[]);
void showPractice08(double season[]);
void fillByStructPractice08(Cost*);
void showByStructPractice08(Cost*);
void Practice08();

//Practice09
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
void Practice09();

//Practice10
double calculate(double a, double b, double (*func)(double x, double y));
double calculate1(double a, double b, double (*func[])(double x, double y));
double add(double, double);
void Practcie10();