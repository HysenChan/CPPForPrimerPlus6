#pragma once
#include<iostream>

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