#pragma once

#include<iostream>
#include<cmath>

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
polar rect_to_polar(rect xyPos);
void show_polar(polar daPos);
void atrctFun();