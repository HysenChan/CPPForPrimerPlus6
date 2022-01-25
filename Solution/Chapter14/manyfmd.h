#pragma once
#include<iostream>

using namespace std;

template<typename T>
class ManyFriend
{
public:
	ManyFriend(const T& i) :item(i) {};
	template<typename C, typename D> friend void show2(C&, D&);

private:
	T item;
};

template<typename C, typename D> void show2(C& c, D& d)
{
	cout << c.item << "," << d.item << endl;
}