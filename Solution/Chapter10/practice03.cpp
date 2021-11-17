#include "practice03.h"

Golf::Golf()
{
	using namespace std;
	char temp[40];
	int hand;
	cout << "Please enter the full name of golf player:";
	cin.getline(temp, 40);
	cout << "Please enter the handicap of golf player:";
	cin >> hand;
	cin.ignore();
	*this = Golf(temp, hand);
}

Golf::Golf(const char* name, int hc)
{
	strcpy_s(fullname, name);
	handicapValue = hc;
}

void Golf::setHandicap(int hc)
{
	handicapValue = hc;
}

void Golf::showgolf()
{
	std::cout << fullname << "," << handicapValue << std::endl;
}

Golf::~Golf()
{
}