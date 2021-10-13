#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
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