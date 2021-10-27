#include"golf.h"
#include "practice.h"

int main()
{
	Practice02();
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