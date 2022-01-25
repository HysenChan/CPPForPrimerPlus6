#include"chapter14_practice.h"
using namespace std;

void Practice02();
void Practice03();

int main()
{
	Practice03();
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