#include"Chapter10_main.h"
#include"stock10.h"
#include"stack.h"
#include"bank.h"
#include"person.h"
#include"practice03.h"
#include "practice04_10.h"
#include"practice05.h"
#include"practice06.h"
#include"practice07.h"

int main()
{
	Practice07();
	//Practice06();
	//Practice05();
	//Practice04();
	//Practice03();
	//Practice02();
	//Practice01();
	//stacker();
	//useStock1();
	//useStock0();
	return 0;
}

void useStock0()
{
	//Stock fluffy_the_cat;//Ĭ�Ϲ��캯��
	//Stock* fluffy_the_cat = new Stock("Furry Mason", 50, 2.5);
	Stock fluffy_the_cat("Furry Mason", 50, 2.5);//Stock fluffy_the_cat = Stock("Furry Mason", 50, 2.5);
	//fluffy_the_cat.acquire("NanoSmatrt", 20, 12.50);
	//Stock fluffy_the_cat{ "Furry Mason", 50, 2.5 };//C++11
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(300000, 40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(300000, 0.125);
	fluffy_the_cat.show();
}

void useStock1()
{
	const int STK = 4;
	Stock stocks[STK] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5),
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STK; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];
	for (st = 0; st < STK; st++)
		top = &top->topval(stocks[st]);

	std::cout << "\nMost valuable holding:\n";
	top->show();
}

void stacker()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a puchase order,\n"
		<< "P to process a PO,or Q to quit.\n";
	while (cin >> ch && _toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
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
			if (st.isFull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isEmpty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye.\n";
}

void Practice01()
{
	using namespace std;
	/*Bank bank1;
	bank1.show();
	Bank bank2 = Bank("name", "account", 0.0);
	bank2.show();*/
	Bank bank3;
	double inPrice, outPrice;
	cout << "Please enter the in price:";
	cin >> inPrice;
	bank3.deposit(inPrice);
	bank3.show();
	cout << "Please enter the out price:";
	cin >> outPrice;
	bank3.takeOut(outPrice);
	bank3.show();
}

void Practice02()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	one.FormalShow();
	std::cout << std::endl;
	two.Show();
	two.FormalShow();
	std::cout << std::endl;
	three.Show();
	three.FormalShow();
	std::cout << std::endl;
}

void Practice03()
{
	Golf ann("Ann Birdfree", 24);
	ann.showgolf();

	Golf ann1;
	ann1.showgolf();
	ann1.setHandicap(100);
	ann1.showgolf();
}

void Practice04()
{
	using namespace SALES_TEN;
	Sale s1;
	s1.setSale();
	s1.showSale();
	Sale s2;
	double arr[2]{ 32.3,34.5 };
	s2.setSale(arr, 2);
	s2.showSale();
}

void Practice05()
{
	using namespace std;
	Stacks st;
	char ch;
	Items temp;
	double totalPayment = 0.0;
	cout << "Please enter A to add customer's information, D to delete customer's information, and Q to quit.\n";
	while (cin >> ch && toupper(ch) != '0')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case'A':
		case'a':
			cout << "Enter the name:";
			cin.getline(temp.fullname, 35);
			cout << "Enter the payment:";
			cin >> temp.payment;
			if (st.isfull())
				cout << "Stack already full.\n";
			else
			{
				st.push(temp);
				st.showStacks();
			}
			break;
		case 'D':
		case 'd':
			if (st.isempty())
				cout << "Stack already empty.\n";
			else
			{
				totalPayment += temp.payment;
				st.pop(temp);
				st.showStacks();
				cout << "The information of " << temp.fullname << " has been deleted.\n";
			}
			break;
		}
		cout << "Please enter A to add customer's information, D to delete customer's information, and Q to quit.\n";
	}
	cout << "total payment is " << totalPayment << endl;
}

void Practice06()
{
	using namespace std;
	Move m0(0, 0);
	Move m1(2, 3);
	std::cout << "m0:";
	m0.showMove();
	std::cout << "m1:";
	m1.showMove();
	double a, b;
	cout << "x:";
	cin >> a;
	cout << "y:";
	cin >> b;
	Move m2(a, b);
	std::cout << "m2:";
	m2.showMove();
	std::cout << "m2 + m0:";
	m2 = m2.add(m0);
	m2.showMove();
	std::cout << "m2 + m1:";
	m2 = m2.add(m1);
	m2.showMove();
	std::cout << "reset x:";
	cin >> a;
	std::cout << "reset y:";
	cin >> b;
	m2.reset(a, b);
	m2.showMove();
}

void Practice07()
{
	Plorg p1;
	p1.ShowPlorg();
	Plorg p2;
	char name[20];
	std::cout << "Please enter the fullName:";
	std::cin.getline(name, 20);
	p2.changeName(name);
	p2.changeCi(30);
	p2.ShowPlorg();
}