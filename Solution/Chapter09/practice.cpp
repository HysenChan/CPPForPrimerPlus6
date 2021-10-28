#include"golf.h"
#include "practice.h"
#include"practice04.h"

int main()
{
	Practice04();
	//Practice03();
	//Practice02();
	//Practice01();
	return 0;
}

void Practice01()
{
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);

	/*golf andy;
	setgolf(andy);
	showgolf(andy);*/

	golf g[3];
	int i = 0;
	while ((i < 3) && (setgolf(g[i])))
	{
		showgolf(g[i]);
		std::cout << "Next golf:\n";
		i++;
	}
}

void Practice02()
{
	using namespace std;
	string input;
	char next;

	cout << "Enter a line:\n";
	getline(cin, input);
	if (input == "")
	{
		std::cout << "Bye\n";
		return;
	}
	while (cin)
	{
		strCount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
		if (input == "")
		{
			std::cout << "Bye\n";
			return;
		}
	}
}

void strCount(const std::string str)
{
	static int total = 0;
	int count = 0;

	std::cout << "\"" << str << "\" contains ";
	while (str[count])
		count++;
	total += count;
	std::cout << count << " character\n";
	std::cout << total << " character total\n";
}

void showChaff(const chaff& c)
{
	using namespace std;
	cout << c.dross << "," << c.slag << endl;
}

void Practice03()
{
	using namespace std;
	/*chaff c[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter dross:";
		cin.getline(c[i].dross, 20);
		cout << "Enter slag:";
		cin >> c[i].slag;
		cin.get();
	}
	for (int i = 0; i < 2; i++)
		showChaff(c[i]);*/

	char buffer1[Buf];
	chaff* cf1 = new(buffer1) chaff[2];
	char* buffer2 = new char[Buf];
	chaff* cf2 = new(buffer2)chaff[2];

	char dross[20] = { 0 };
	int slag = 0;

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter dross:";
		cin.getline(dross, 20);
		cout << "Enter slag:";
		cin >> slag;
		cin.ignore();
		strcpy_s(cf1[i].dross, dross);
		strcpy_s(cf2[i].dross, dross);
		cf1[i].slag = cf2[i].slag = slag;
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "chaff $" << i + 1 << ":\n";
		cout << "cf1.dross:" << cf1[i].dross << ",cf1.slag:" << cf1[i].slag << endl;
		cout << "cf2.dross:" << cf2[i].dross << ",cf2.slag:" << cf2[i].slag << endl;
	}

	delete[] buffer2;
}

void Practice04()
{
	const int salesSize = 2;
	using namespace SALES;
	/*Sales s1;
	setSales(s1);
	showSales(s1);*/

	Sales* s2 = new Sales[salesSize];
	for (int i = 0; i < salesSize; i++)
	{
		std::cout << "Please enter NO." << i + 1 << " data:\n";
		setSales(s2[i]);
		showSales(s2[i]);
	}
}