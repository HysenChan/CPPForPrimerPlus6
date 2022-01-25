#pragma once
#include<iostream>

template<typename T> void counts();
template<typename T> void report(T&);

template<typename TT>
class HasFriendT
{
public:
	HasFriendT(const TT& i) :item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);

private:
	TT item;
	static int ct;
};

template<typename T>
int HasFriendT<T>::ct = 0;

template<typename T>
void counts()
{
	cout << "template size:" << sizeof(HasFriendT<T>) << ";";
	cout << "template counts():" << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T& hf)
{
	cout << hf.item << endl;
}