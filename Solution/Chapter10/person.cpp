#include"person.h"

//Person::Person()
//{
//}

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

void Person::Show() const
{
	std::cout << "fName-lName:" << fname << "-" << lname << std::endl;
}

void Person::FormalShow() const
{
	std::cout << "lName-fName:" << lname << "-" << fname << std::endl;
}

Person::~Person()
{
}