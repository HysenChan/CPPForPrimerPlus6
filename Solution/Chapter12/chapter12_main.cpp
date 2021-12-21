#include"chapter12_main.h"
#include"stringBad.h"
#include"stringOfficial.h"

int main()
{
	vegnews1();
	//vegnews();
	return 0;
}

void callme1(StringBad& rsb)
{
	using std::cout;
	cout << "String psssed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad vsb)
{
	using std::cout;
	cout << "String psssed by value:\n";
	cout << "    \"" << vsb << "\"\n";
}

void vegnews()
{
	using std::cout;
	using std::endl;
	cout << "Starting an inner block.\n";
	StringBad headline1("AAAAA");
	StringBad headline2("BBBBB");
	StringBad sports("CCCCC");

	cout << "headline1:" << headline1 << endl;
	cout << "headline2:" << headline2 << endl;
	cout << "sports:" << sports << endl;
	callme1(headline1);
	cout << "headline1:" << headline1 << endl;
	callme2(headline2);
	cout << "headline2:" << headline2 << endl;
	cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	cout << "sailor:" << sailor << endl;
	cout << "Assign one object to another:\n";
	StringBad knot;
	knot = headline1;
	cout << "Knot:" << knot << endl;
	cout << "Exiting the block.\n";
}

void callme3(String& rsb)
{
	using std::cout;
	cout << "String psssed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme4(String vsb)
{
	using std::cout;
	cout << "String psssed by value:\n";
	cout << "    \"" << vsb << "\"\n";
}

void vegnews1()
{
	using std::cout;
	using std::endl;
	String opera("The Magic Flute");
	cout << opera[2] << endl;
	String means("might");
	means[0] = 'r';
	cout << means << endl;
}