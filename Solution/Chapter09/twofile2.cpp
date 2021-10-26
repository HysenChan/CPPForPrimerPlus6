#include"Chapter09_main.h"

extern int tom;
static int dick = 10;
int harry = 200;

void remote_access()
{
	cout << "remote_access() reports the following addresses:\n";
	cout << &tom << " = &tom, tom = " << tom << "," << &dick << " = &dick, ";
	cout << &harry << " = &harry.\n";
}