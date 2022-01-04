#include"chatper13_practice01.h"

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy_s(performers, 50, s1);
	strcpy_s(label, 20, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy_s(performers, 50, "null");
	strcpy_s(label, 20, "null");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	using namespace std;
	cout << "----------------------\n";
	cout << "performers:" << performers << endl;
	cout << "label:" << label << endl;
	cout << "selections:" << selections << endl;
	cout << "playTime:" << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* s0, const  char* s1, const  char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	strcpy_s(mainworks, 50, s0);
}

Classic::Classic(char* s0, Cd& rs) : Cd(rs)
{
	strcpy_s(mainworks, 50, s0);
}

Classic::Classic() : Cd()
{
	strcpy_s(mainworks, 50, "null");
}

Classic::~Classic()
{
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "mainworks:" << mainworks << std::endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;

	Cd::operator=(c);
	strcpy_s(mainworks, 50, c.mainworks);
	return *this;
}