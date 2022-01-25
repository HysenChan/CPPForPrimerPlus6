#include"chapter14_practice.h"
using namespace std;

void Practice02();
void Practice03();
void Practice04();

int main()
{
	Practice04();
	//Practice03();
	//Practice02();
}

void Practice02()
{
	cout << "Enter name of wine:";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years:";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() << ":" << more.sum() << endl;
	cout << "Bye.\n";
}

void Practice03()
{
	QueueTP<Worker>* Qworker = new QueueTP<Worker>(20);
	Worker w1("Leonardo", 1024);
	Worker w2("Elma", 2035);
	if (Qworker->isempty())
		cout << "Qworker is empty!\n";
	Qworker->enqueue(w1);
	Qworker->enqueue(w2);
	cout << "Qworker count:" << Qworker->queuecount() << endl;
	Worker w3("hello", 2);
	Qworker->enqueue(w3);
	Qworker->enqueue(w2);
	cout << "Qworker count:" << Qworker->queuecount() << endl;
	Worker temp;
	Qworker->dequeue(temp);
	cout << "Dequeue:" << endl;
	temp.Show();
	Qworker->dequeue(temp);
	cout << "Dequeue:" << endl;
	temp.Show();
	cout << "Qworker count:" << Qworker->queuecount() << endl;
}

void Practice04()
{
	srand(time(0));
	const int SIZE = 4;

	Person* p[SIZE];
	int i;
	for (i = 0; i < SIZE; i++)
	{
		char flag;
		cout << "Enter the person category:\n" << "g: Gunslinger  p: PokerPlayer  b: BadDude  q: Quit\n";
		cin >> flag;
		cin.ignore();
		while (strchr("gpbq", flag) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> flag;
			cin.ignore();
		}
		if (flag == 'q')
		{
			break;
		}
		string fname;
		string lname;
		int n = 0;
		double t = 0;
		cout << "Please enter the first name: ";
		getline(cin, fname);
		cout << "Please enter the last name: ";
		getline(cin, lname);
		switch (flag)
		{
		case 'g':
			cout << "Please enter the nicks: ";
			cin >> n;
			cout << "Please enter the \"Gun Out\" time: ";
			cin >> t;
			p[i] = new Gunslinger(fname, lname, n, t);
			break;
		case 'p':
			p[i] = new PokerPlayer(fname, lname);
			break;
		case 'b':
			cout << "Please enter the nicks: ";
			cin >> n;
			cout << "Please enter the \"Gun Out\" time: ";
			cin >> t;
			p[i] = new BadDude(fname, lname, n, t);
			break;
		}
	}
	cout << "\nHere is your person:\n";
	int j;
	for (j = 0; j < i; j++)
	{
		cout << endl;
		p[j]->Show();
	}
	for (j = 0; j < i; j++)
		delete p[j];
	cout << "Bye\n";

}