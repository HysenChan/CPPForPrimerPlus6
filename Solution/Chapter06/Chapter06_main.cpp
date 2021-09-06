#include"Chapter06_main.h"

int main()
{
	Practice03();
	//Practice02();
	//Practice01();
	//Review09();
	//Review07();
	//Review06();
	//Review05();
	//Review04();
	//Review03();
	//SumaFile();
	//InFile();
	//OutFile();
	//CinCoutFile();
	//CinGolf();
	//CinFish();
	//Jump();
	//EnumBase();
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

void Jump()
{
	using namespace std;
	const int ArSize = 80;
	char line[ArSize];
	int spaces = 0;
	cout << "Enter a line of text:\n";
	cin.get(line, ArSize);
	cout << "Complete line:\n" << line << endl;
	cout << "Line through first period:\n";
	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];
		if (line[i] == '.')
			break;
		if (line[i] != ' ')
			continue;
		if (line[i] == 'H' || line[i] == 'h')
			goto catchChar;
		spaces++;
	}
catchChar:cout << "\nCatch a H\n";
	cout << "\n" << spaces << " spaces\n";
	cout << "Done.\n";
}

void CinFish()
{
	const int Max = 5;
	using namespace std;
	double fish[Max];
	cout << "enter the weights and up to " << Max << " fish\n";
	cout << "fish #1:";
	int i = 0;
	while (i<Max && cin >> fish[i])
	{
		if (++i < Max)
			cout << "fish #" << i + 1 << ":";
	}
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];
	if (i == 0)
		cout << "No fish\n";
	else
		cout << total / i << " = average of " << i << " fish\n";
	cout << "Done.\n";
}

void CinGolf()
{
	using namespace std;
	const int Max = 5;
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number:";
		}
	}
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << total / Max << " = average score " << Max << " rounds\n";
}

void CinCoutFile()
{
	using namespace std;
	ofstream outFile;
	ofstream fout;

	outFile.open("fish.txt");
	double wt = 125.8;
	int it = 10;
	outFile << wt;
	outFile << it;

	char fileName[50] = "Hello.txt";
	fout.open(fileName);
	char line[81] = "This is Objects are closer than they appear.";
	fout << line << endl;
}

void OutFile()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "Enter the make and model of automobile:";
	cin.getline(automobile, 50);
	cout << "Enter the model year:";
	cin >> year;
	cout << "Enter the original asking price:";
	cin >> a_price;
	d_price = 0.913 * a_price;
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model:" << automobile << endl;
	cout << "Year:" << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model:" << automobile << endl;
	outFile << "Year:" << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	outFile.close();
}

void InFile()
{
	using namespace std;
	ifstream inFile;
	ifstream fin;

	inFile.open("bowling.txt");
	if (!inFile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	char fileName[50];
	cin >> fileName;
	fin.open(fileName);

	double wt;
	inFile >> wt;
	char line[81];
	fin.getline(line, 81);
}

void SumaFile()
{
	using namespace std;

	const int SIZE = 60;
	char fileName[SIZE] = "scores.txt";
	ifstream inFile;
	cout << "Enter name of data file:\n";
	//cin.getline(fileName, SIZE);
	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << fileName << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;

	while (inFile >> value)
	{
		++count;
		sum += value;
	}
	if (inFile.eof())//最后一次读取数据时遇到EOF,返回true
		cout << "End of file reached.\n";
	else if (inFile.fail())//最后一次读取操作中发生类型不匹配，fail()返回true；例如scores.txt中的name和其他类型不匹配
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)//指定文件里没有数据
		cout << "No data processed.\n";
	else
	{
		cout << "Items read:" << count << endl;
		cout << "Sum:" << sum << endl;
		cout << "Average:" << sum / count << endl;
	}
	inFile.close();
}

void Review03()
{
	using namespace std;
	char ch;
	int ct1, ct2;

	ct1 = ct2 = 0;
	while ((ch = cin.get() != '$'))
	{
		cout << ch;
		ct1++;
		if (ch = '$')
			ct2++;
		cout << ch;
	}
	cout << "ct1=" << ct1 << ",ct2=" << ct2 << endl;
}

void Review04()
{
	using namespace std;
	int weight = 120;
	if (weight >= 115 && weight < 125)
		cout << "weight:" << weight << endl;
	char ch = 'q';
	if (ch == 'q' || ch == 'Q')
		cout << "ch:" << ch << endl;
	int x = 30;
	if (x != 26 && x % 2 == 0)
		cout << "x:" << x << endl;
	if (!(x % 26 == 0) && x % 2 == 0)
		cout << "x:" << x << endl;
	int donation = 999;
	int guest = 1;
	if ((donation > 1000 && donation < 2000) || guest == 1)
		cout << "donation:" << donation << ",guest:" << guest << endl;
	if (isupper(ch))//(ch>='A'&&ch<='Z')
		cout << "ch is uppper.\n";
	else if (islower(ch))//(ch>='a'&&ch<='z')
		cout << "ch is lower.\n";
}

void Review05()
{
	using namespace std;
	int x = 10;
	cout << "x:" << x << ",!x:" << !x << ",!!x:" << !!x << endl;
	bool y = true;
	cout.setf(ios_base::boolalpha);
	cout << "y:" << y << ",!y:" << !y << ",!!y:" << !!y << endl;
}

void Review06()
{
	using namespace std;
	int x;
	cin >> x;
	x = (x >= 0) ? x : -x;
	cout << x;
}

void Review07()
{
	using namespace std;
	char ch;
	int a_grade = 0, b_grade = 0, c_grade = 0, d_grade = 0, f_grade = 0;
	cin >> ch;
	switch (ch)
	{
	case 'A':
		a_grade++;
		break;
	case 'B':
		b_grade++;
		break;
	case 'C':
		c_grade++;
		break;
	case 'D':
		d_grade++;
		break;
	default:
		f_grade++;
		break;
	}
	cout << "a_grade:" << a_grade << endl;
	cout << "b_grade:" << b_grade << endl;
	cout << "c_grade:" << c_grade << endl;
	cout << "d_grade:" << d_grade << endl;
	cout << "f_grade:" << f_grade << endl;
}

void Review09()
{
	using namespace std;
	int line = 0;
	char ch;
	while (cin.get(ch) && ch != 'Q')
	{
		if (ch != '\n')
			line++;
	}
	cout << "line:" << line << endl;
}

void Practice01()
{
	using namespace std;
	char ch;
	while (cin.get(ch) && ch != '@')
	{
		if (isdigit(ch) or isspace(ch))//排除数字和空格
			cout << ch;
		else
		{
			ch = isupper(ch) ? tolower(ch) : toupper(ch);
			cout << ch;
		}
	}
}

void Practice02()
{
	using namespace std;
	const int ArraySize = 10;
	double donation[ArraySize];
	int length = 0;
	double sum = 0;
	int overAverageNum = 0;
	cout << "Please enter double type num:\n";
	while (cin >> donation[length] && length < ArraySize - 1)
	{
		sum += donation[length];
		length++;
	}
	for (int i = 0; i < length; i++)
	{
		if (donation[i] > sum / length)
			overAverageNum++;
	}
	cout << "sum:" << sum << ",average:" << sum / length << endl;
	cout << "overAverageNum:" << overAverageNum << endl;
}

void Practice03()
{
	using namespace std;
	char ch;
	cout << "Please enter one of the floowing choices:\n";
	while (cin.get(ch))
	{
		switch (ch)
		{
		case 'c':
			cout << "carnivore.";
			break;
		case 'p':
			cout << "pianist.";
			break;
		case 't':
			cout << "tree.";
			break;
		case 'g':
			cout << "game.";
			break;
		default:
			cout << "\nPlease enter one of the floowing choices:\n";
			break;
		}
		cin.ignore();
		cin.clear();
	}
}