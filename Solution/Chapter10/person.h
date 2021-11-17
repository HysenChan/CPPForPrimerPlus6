#pragma once
#include<iostream>
#include<string>

class Person
{
public:
	Person() { lname = "", fname[0] = '\0'; };
	Person(const std::string& ln, const char* fn = "Heyyou");
	void Show() const;
	void FormalShow()const;
	~Person();

private:
	static const int LIMIt = 25;
	std::string lname;
	char fname[LIMIt];
};
