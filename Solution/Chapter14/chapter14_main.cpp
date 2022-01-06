#include"chapter14_main.h"
#include"studentc.h"
#include"Worker0.h"
using namespace std;

int main()
{
	worktest();
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
