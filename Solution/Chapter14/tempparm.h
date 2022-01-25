#pragma once
#include<iostream>
#include"stacktp.h"

template<template <typename T> class Thing>
class Crab
{
public:
	Crab() {};
	bool push(int a, double x) {
		return s1.push(a) && s2.push(x);
	}
	bool pop(int& a, double& x) {
		return s1.pop(a) && s2.pop(x);
	}

private:
	Thing<int> s1;
	Thing<double> s2;
};

