#include "golf.h"

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	handicap(g, hc);
}

int setgolf(golf& g)
{
	using std::cout;
	using std::cin;
	using std::endl;
	char name[Len];
	int hc;
	cout << "Please enter the name:";
	cin.getline(name, Len);
	if (strcmp(name, "") == 0)
		return 0;
	cout << "Please enter the hc:";
	cin >> hc;
	setgolf(g, name, hc);
	cin.get();
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << g.fullname << "," << g.handicap << std::endl;
}
