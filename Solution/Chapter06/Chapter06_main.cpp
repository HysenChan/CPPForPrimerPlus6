#include"Chapter06_main.h"

int main()
{
	IfElseifElseBase();
	//IfElseBase();
	//IfBase();
	return 0;
}

void IfBase()
{
	using namespace std;
	char ch;
	int spaces = 0;
	int total = 0;
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == ' ')
		{
			++spaces;
		}
		++total;
		cin.get(ch);
	}
	cout << "Spaces:" << spaces << endl;
	cout << "Total char:" << total << endl;
}

void IfElseBase()
{
	using namespace std;
	char ch;
	cout << "Type, and I shall repeat.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
		{
			cout << ch;
		}
		else
		{
			cout << ++ch;//ch+1输出为每个字符对应的ASCII码
		}
		cin.get(ch);
	}
	cout << "\nPlease excuse the slight confusion.\n";
}

void IfElseifElseBase()
{
	using namespace std;
	int Fave = rand() % 100;
	cout << "Fave:" << Fave << endl;
	int n;

	cout << "Enter a number in the range 1-100 to find";
	cout << "my favorite number:";
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "Too low -- guess again:";
		else if (n > Fave)
			cout << "Too high -- guess again:";
		else
			cout << Fave << " is right!\n";
	} while (n != Fave);
}
