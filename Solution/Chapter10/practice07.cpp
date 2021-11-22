#include"practice07.h"

Plorg::Plorg(const char* defaultName, int defaultCi)
{
	strcpy_s(fullname, defaultName);
	ci = defaultCi;
}

void Plorg::changeName(const char* name)
{
	strcpy_s(fullname, name);
}

void Plorg::changeCi(int newCi)
{
	ci = newCi;
}

void Plorg::ShowPlorg() const
{
	std::cout << "fullname:" << fullname << ",ci:" << ci << std::endl;
}

Plorg::~Plorg()
{
}