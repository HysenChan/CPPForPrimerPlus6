#pragma once
#include<iostream>
template<class T1, class T2>
class Pair
{
public:
	T1& first();
	T2& second();
	T1 first()const { return a; }
	T2 second()const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}

private:
	T1 a;
	T2 b;
};

template<class T1, class T2>
inline T1& Pair<T1, T2>::first()
{
	return a;
}

template<class T1, class T2>
inline T2& Pair<T1, T2>::second()
{
	return b;
}
