#pragma once
#include<iostream>
using namespace std;
template<typename T>
class beta
{
public:
	beta(T t, int i) :q(t), n(i) {};
	template<typename U>
	U blab(U u, T t);
	void Show()const { q.show(); n.show(); }

private:
	template<typename V>
	class hold;
	hold<T> q;
	hold<int> n;
};

template <typename T>
template<typename V>
class beta<T>::hold
{
public:
	hold(V v = 0) :val(v) {};
	void show()const { cout << val << endl; }
	V Value()const { return val; }

private:
	V val;
};

template<typename T>
template<typename U>
U beta<T>::blab(U u, T t)
{
	return (n.Value() + q.Value()) * u / t;
}