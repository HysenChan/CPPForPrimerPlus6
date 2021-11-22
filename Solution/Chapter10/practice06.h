#pragma once
#include<iostream>

class Move
{
public:
	Move(double a = 0,double b = 0);
	void showMove() const;
	Move add(const Move& m)const;
	void reset(double a = 0, double b = 0);
	~Move();

private:
	double x;
	double y;
};