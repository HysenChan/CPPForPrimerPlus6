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