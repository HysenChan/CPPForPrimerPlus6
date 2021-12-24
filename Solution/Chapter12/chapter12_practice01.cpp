#include"chapter12_practice01.h"

Cow::Cow()
{
	strcpy_s(name, 20, "new cow");
	hobby = new char[4];
	strcpy_s(hobby, 4, "cow");
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	delete[] hobby;
	strcpy_s(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "-----------------\n";
	std::cout << "name:" << name << std::endl;
	std::cout << "hobby:" << hobby << std::endl;
	std::cout << "weight:" << weight << std::endl;
}
