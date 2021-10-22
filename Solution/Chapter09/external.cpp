#include"Chapter09_main.h"

int errors = 5;

double warming = 0.3;
void update(double dt);
void local();
void show();

int main2()
{
	/*cout << "Global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";*/
	show();
	cout << errors << endl;
	return 0;
}