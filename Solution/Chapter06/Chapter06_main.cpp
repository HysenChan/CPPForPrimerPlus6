#include"Chapter06_main.h"

int main()
{
	EnumBase();
	//SwitchBase();
	//Condit();
	//CCTypes();
	//NotBase();
	//MoreAndBase();
	//AndBase();
	//OrBase();
	//IfElseifElseBase();
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

void OrBase()
{
	using namespace std;
	cout << "This program may reformat your hard disk\n"
		"and destroy all your data.\n"
		"Do you wish to continue?<y/n>";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		cout << "You were warned!\a\a\n";
	else if (ch == 'n' || ch == 'N')
		cout << "A wise choice ... buy\n";
	else
		cout << "That wasn't a y or n!";
}

void AndBase()
{
	using namespace std;
	const int ArSize = 6;
	float naaq[ArSize];
	cout << "Enter a value:" << ArSize << endl;

	int i = 0;
	float temp;
	cout << "First value:";
	cin >> temp;
	while (i < ArSize && temp >= 0)
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)
		{
			cout << "Next value:";
			cin >> temp;
		}
	}
	if (i == 0)
	{
		cout << "No data--by\n";
	}
	else
	{
		cout << "Enter your NAAQ:";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			if (naaq[j] > you)
			{
				++count;
			}
		}
		cout << count;
		cout << " biger than you have totals.\n";
	}
}

void MoreAndBase()
{
	using namespace std;

	const char* qualify[4] =
	{
		"One",
		"Two",
		"Three",
		"Four",
	};

	int age;
	cout << "Enter your age in years:";
	cin >> age;
	int index;

	if (age > 17 && age < 35)
		index = 0;
	else if (age > 35 && age < 50)
		index = 1;
	else if (age >= 50 && age < 65)
		index = 2;
	else
		index = 3;

	cout << "Your qualify for the " << qualify[index];
}

void NotBase()
{
	using namespace std;

	double num;

	cout << "Yo,dude!Enter an integer value:";
	cin >> num;
	while (!is_int(num))
	{
		cout << "Out of range -- please try again:";
		cin >> num;
	}

	int val = int(num);
	cout << "You've entered the integer " << val << "\nBye\n";
}

bool is_int(double x)
{
	if (x <= INT_MAX && x >= static_cast<int>(INT_MIN))
		return true;
	else
		return false;
}

void CCTypes()
{
	using namespace std;
	cout << "Enter text for analysis,and type@"
		" to terminate input.\n";
	char ch;
	int whitespace = 0, digits = 0, chars = 0, punct = 0, others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else
			others++;
		cin.get(ch);
	}
	cout << chars << " letters, " << whitespace << " whitespace, " << digits << " digits, " << others << " others.\n";
}

void Condit()
{
	using namespace std;
	int a, b;
	cout << "Enter two integers:";
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b;
	int c = a > b ? a : b;
	cout << " is " << c << endl;
}

void showmenu();
void report();
void comfort();
void SwitchBase()
{
	using namespace std;
	showmenu();
	char choice;
	cin >> choice;
	while (choice != 'q' && choice != 'Q')
	{
		switch (choice)
		{
		case 'a':
		case 'A':	cout << "\a\n";
			break;
		case 'r':
		case 'R':	report();
			break;
		case 'l':
		case 'L':	cout << "The boss was in all day.\n";
			break;
		case 'c':
		case 'C':	comfort();
			break;
		default:cout << "That's not a choice.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Bye!\n";
}

void showmenu()
{
	std::cout << "Please enter a,r,l,c,or q:\n"
		"a) alarm		r)report\n"
		"l) alibi		c)comfort\n"
		"q) quit\n";
}

void report()
{
	std::cout << "It's been an excellent week for business.\n"
		"Sales are up 120%. Expenses are down 35%.\n";
}

void comfort()
{
	std::cout << "Your employees think ou are the finest CEO\n"
		"in the industry.The board of directors think\n"
		"you are the finest CEO in the industry.\n";
}

void EnumBase()
{
	enum { red, orange, yellow, green, blue, violet, indigo };
	using namespace std;
	cout << "Enter color code (0-6):";
	int code;
	cin >> code;
	while (!isdigit(code) && code >= red && code <= indigo)
	{
		switch (code)
		{
		case red:cout << "Red!\n"; break;
		case orange:cout << "Orange!\n"; break;
		case yellow:cout << "Yellow!\n"; break;
		case green:cout << "Green!\n"; break;
		case blue:cout << "Blue!\n"; break;
		case violet:cout << "Violet!\n"; break;
		case indigo:cout << "Indigo!\n"; break;
		}
		cout << "Enter color code(0-6):";
		cin >> code;
	}
	cout << "Bye\n";
}