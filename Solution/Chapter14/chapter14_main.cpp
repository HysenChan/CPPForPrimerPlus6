#include"chapter14_main.h"
#include"studentc.h"
#include"Worker0.h"
#include"stacktp.h"
#include<ctime>
#include"arraytp.h"
#include"pairs.h"
#include"tempmemb.h"
using namespace std;

int main()
{
	tempmenb();
	//pairs();
	//twod();
	//stkoptr1();
	//stacktem();
	//workmi();
	//worktest();
	//use_stuc();
	return 0;
}

void set(Student& sa, int n)
{
	cout << "Please enter the student's name:";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz socres:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}

void use_stuc()
{
	Student ada[pupils] = { Student(quizzes),Student(quizzes),Student(quizzes) };

	int i;
	for (i = 0; i < pupils; ++i)
		set(ada[i], quizzes);
	cout << "\nStudent List:\n";
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\nResults:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "average:" << ada[i].Average() << endl;
	}
	cout << "Done.\n";
}

void worktest()
{
	const int LIM = 4;

	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob,&bev,&w_temp,&s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << endl;
	}
}

void workmi()
{
	const int SIZE = 5;

	Worker* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter s: singer "
			<< "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w,s,t,or q:";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
}

void stacktem()
{
	Stack<std::string>st;
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isgraph(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add:";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
				break;
			}
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye.\n";
}

void stkoptr1()
{
	const int Num = 10;

	std::srand(std::time(0));
	std::cout << "Please enter stack size:";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char*> st(stacksize);

	const char* in[Num] = {
		" 1: A", " 2: B",
		" 3: C", " 4: D",
		" 5: E", " 6: F",
		" 7: G", " 8: H",
		" 8: I", " 10: J",
	};

	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;
	std::cout << "Bye.\n";
}

void twod()
{
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";
}

void pairs()
{
	Pair<string, int> ratings[4] =
	{
		Pair<string,int>("The Purpled Duck",5),
		Pair<string,int>("Jaquie's Frisco Al Fresco",4),
		Pair<string,int>("Cafe Souffle",5),
		Pair<string,int>("Bertie's Eats",3),
	};

	int joints = sizeof(ratings) / sizeof(Pair<string, int>);
	cout << "Rating:\t Eatery\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
	cout << "Oops!Revised rating:\n";
	ratings[3].first() = "Bertie's Fab Eats";
	ratings[3].second() = 6;
	cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;
}

void tempmenb()
{
	beta<double> guy(3.5, 3);
	cout << "T was set to double\n";
	guy.Show();
	cout << "V was set to T, which is double, then V was set to int\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U was set to int\n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U was set to double\n";
	cout << "Done\n";
}
