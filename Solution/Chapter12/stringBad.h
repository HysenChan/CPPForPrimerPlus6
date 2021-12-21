#pragma once
#include<iostream>
#include<string>
#pragma warning(disable : 4996)
using namespace std;

class StringBad
{
public:
	StringBad();
	StringBad(const char* s);
	StringBad(const StringBad& st);
	StringBad& operator=(const StringBad& st);
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);

private:
	char* str;
	int len;
	static int num_strings;
};
