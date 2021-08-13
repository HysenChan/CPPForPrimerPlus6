#include"Chapter05_main.h"

int main()
{
	Practice03();
	//Practice02();
	//Practice01();
	//Test07();
	//MultiDoubleForLoop();
	//TwoDimentionalArray();
	//Textin4();
	//Textin3();
	//Textin1();
	//ForLoopInCpp11();
	//DoWhile();
	//Block();
	//Waiting();
	//WhileLoop();
	//CompStr2();
	//CompStr1();
	//ForStr3();
	//Equal();
	//CommaPriority();
	//ForStr2();
	//ExternalAndInnernalValue();
	//PointerPlus();
	//PlusOne();
	//ForStr1();
	//BigStep();
	//Formore();
	//Express();
	//NumTest();
	//ForLoop();
	return 0;
}

void ForLoop()
{
	using namespace std;
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << "i value:" << i << endl;
		cout << "C++ knows loops.\n";
	}
	cout << "C++ knows when to stop.\n";
}

void NumTest()
{
	using namespace std;
	cout << "Enter the starting countdown value:";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--)
	{
		cout << "i = " << i << endl;
	}
	cout << "Done now that i = " << i << endl;
}

void Express()
{
	using namespace std;
	int x;

	cout << "The expression x = 100 has the value " << (x = 100) << endl;
	cout << "Now x = " << x << endl;
	cout << "The expression x < 3 has the value " << (x < 3) << endl;
	cout << "The expression x > 3 has the value " << (x > 3) << endl;
	cout.setf(ios_base::boolalpha);
	cout << "The expression x < 3 has the value " << (x < 3) << endl;
	cout << "The expression x > 3 has the value " << (x > 3) << endl;
}

void Formore()
{
	using namespace std;
	const int ArSize = 16;

	long long factorials[ArSize];
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < ArSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}
	for (int i = 0; i < ArSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}
}

void BigStep()
{
	using namespace std;
	cout << "Enter an integer:";
	int by;
	cin >> by;
	cout << "Counting by " << by << endl;
	for (int i = 0; i < 100; i += by)
	{
		cout << "i:" << i << endl;
	}
}

void ForStr1()
{
	using namespace std;
	cout << "Enter a word:";
	string word;
	cin >> word;

	for (int i = word.size() - 1; i >= 0; i--)
	{
		cout << word[i];
	}
	cout << "\nBye.\n";
}

void PlusOne()
{
	using namespace std;
	int a = 20;
	int b = 20;
	cout << "a = " << a << ": b = " << b << "\n";
	cout << "a++ = " << a++ << ": ++b = " << ++b << "\n";
	cout << "a = " << a << ": b = " << b << "\n";
}

void PointerPlus()
{
	using namespace std;
	double arr[5] = { 21.1,32.8,23.4,45.2,37.4 };
	double* pt = arr;
	cout << "*pt:" << *pt << endl;//21.1
	cout << "*pt++:" << *pt++ << endl;//21.1
	cout << "*pt:" << *pt << endl;//32.8
	cout << "*++pt:" << *++pt << endl;//23.4
	cout << "++*pt" << ++ * pt << endl;//24.4
}

void ExternalAndInnernalValue()
{
	using namespace std;
	int x = 20;
	{
		cout << x << endl;
		int x = 200;
		cout << x << endl;
	}
	cout << x << endl;
}

void ForStr2()
{
	using namespace std;
	cout << "Enter a word:";
	string word;
	cin >> word;

	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		cout << "i:" << i;
		cout << "temp:" << temp;
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << "\nDone\n";
}

void CommaPriority()
{
	using namespace std;
	int cat = (17, 240);
	cout << "cat:" << cat << endl;//240	括号优先级最高，逗号运算符优先级最低；
}

void Equal()
{
	using namespace std;
	int quizscores[10] = { 20,20,20,20,20,19,20,18,20,20 };
	cout << "Doing it right:\n";
	int i;
	for (i = 0; quizscores[i] == 20; i++)
	{
		cout << "-- 1 quiz " << i << " is a 20\n";
	}
	cout << "Doing it dangerously wrong:\n";
}

void ForStr3()
{
	using namespace std;
	char ch;
	for (ch = 'a'; ch <= 'z'; ch++)
		cout << ch;
}

void CompStr1()
{
	using namespace std;
	char word[5] = "?ate";
	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
}

void CompStr2()
{
	using namespace std;
	string word = "?ate";

	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
}

void WhileLoop()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	//string name;

	cout << "Your first name, please:";
	cin >> name;
	cout << "Here is your name, verticalized and ASCIIized:\n";
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;
	}
}

void Waiting()
{
	using namespace std;
	cout << "Enter the delay time, in second:";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay);
	cout << "done \a\n";
}

void Block()
{
	using namespace std;
	cout << "The amazing accounto will sum and average five number for you.\n";
	cout << "Please enter five values:\n";
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Value " << i << ":";
		cin >> number;
		sum += number;
	}
	cout << "Five exquisite choices indeed!";
	cout << "They sum to " << sum << endl;
	cout << "and average to " << sum / 5 << endl;
	cout << "The amazing accounto bids you adieu!\n";
}

void DoWhile()
{
	using namespace std;
	int num;
	cout << "Enter numbers in the range 1-10 to find ";
	cout << "my favorite number\n";
	do
	{
		cin >> num;
	} while (num != 8);
	cout << "Yes," << num << " is my favorite.\n";
}

void ForLoopInCpp11()
{
	using namespace std;
	double prices[5] = { 4.99,10.99,6.89,7.23,9.11 };
	for (double x : prices)//display values
		cout << x << endl;
	for (double& x : prices)//change values
	{
		x = x * 0.80;
		cout << x << endl;
	}
	for (int x : {3, 5, 6, 8, 9})
		cout << x << " ";
}

void Textin1()
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	cin.get(ch);
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
}

void Textin3()
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch);
	while (!cin.fail())
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
}

void Textin4()
{
	using namespace std;
	int ch;
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " character read\n";
}

void TwoDimentionalArray()
{
	using namespace std;
	const int Cities = 5;
	const int Years = 4;

	//char citites[Citites][25] char 可以存储24个字符串（'\0'结束符)
	//string citites[Citites]	string 自动调节字符串长度
	const char* citites[Cities] =
	{
		"Gribble City",
		"Gribble town",
		"New Gribble",
		"San Gribble",
		"Gribble Vista",
	};

	int maxtemps[Years][Cities] =
	{
		{96,100,87,101,105},
		{96,98,91,107,104},
		{97,101,03,108,107},
		{98,103,95,109,108},
	};

	cout << "Maximum temperatures for 2008 - 2011\n\n";
	for (int city = 0; city < Cities; city++)
	{
		cout << citites[city] << ":\t";
		for (int year = 0; year < Years; year++)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	}
}

void MultiDoubleForLoop()
{
	using namespace std;
	for (int i = 1; i <= 64; i *= 2)
		cout << "i:" << i << '\t';
}

void Test07()
{
	using namespace std;
	int x = (1, 024);//{}是代码块
	cout << "x:" << x << endl;//x=20(八进制)
	int y;
	y = 1, 024;
	cout << "y:" << y << endl;//y=1;024无用代码
}

void Practice01()
{
	using namespace std;
	int num1, num2, sum = 0;
	cout << "Please enter start num:";
	cin >> num1;
	cout << "Please enter end num:";
	cin >> num2;
	if (num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	for (int i = num1; i <= num2; i++)
		sum += i;
	cout << "sum:" << sum << endl;
}

void Practice02()
{
	using namespace std;
	const int ArSize = 101;

	array<long double, ArSize> factorials;
	factorials[1] = factorials[0] = 1;
	for (int i = 2; i < ArSize; i++)
	{
		factorials[i] = i * factorials[(double)i - 1];
	}
	for (int i = 0; i < ArSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}
}

void Practice03()
{
	using namespace std;
	int num;
	int sum = 0;
	cout << "Please enter num:";
	cin >> num;
	while (num != 0)
	{
		sum += num;
		cout << "Sum:" << sum << endl;
		cout << "Please enter num:";
		cin >> num;
	}
	cout << "Sum:" << sum << endl;
}