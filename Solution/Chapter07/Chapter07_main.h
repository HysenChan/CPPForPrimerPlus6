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

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);
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

void review10(const glitz *g);

//Review11
int review11(int (*pf)(const char*));