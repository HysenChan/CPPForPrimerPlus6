#pragma once
#include<iostream>
#include<string>
#pragma warning(disable : 4996)
using namespace std;

class String
{
public:
	String();
	String(const char* s);
	String(const String& st);
	String& operator=(const String& st);
	String& operator=(const char* s);
	int length() const { return len; }
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend std::istream& operator>>(istream& is, String& st);
	char& operator[](int i);
	const char& operator[](int i)const;
	static int HowMany();
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	~String();

private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
};
