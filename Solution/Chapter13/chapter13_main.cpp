#include"chapter13_main.h"
#include"tabtenn0.h"
//#include"brass.h"
#include"acctabc.h"
#include"dma.h"
#include"chatper13_practice01.h"
#include"chapter13_practice04.h"

int main()
{
	Practice04();
	//Practice01();
	//usedma();
	//usebrass3();
	//usebrass2();
	//usebrass1();
	//usett1();
	//usett0();
	return 0;
}

void usett0()
{
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
}

void usett1()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	cout << "Name:";
	rplayer1.Name();
	cout << ";Rating:" << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1);
	cout << "Name:";
	rplayer2.Name();
	cout << ";Rating:" << rplayer2.Rating() << endl;
}

void usebrass1()
{
	using namespace std;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account:\n";
	Hoggy.Deposit(1000.00);
	cout << "New balance:$" << Hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Pigg Account:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg account balance:$" << Piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg Account:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}

//void usebrass2()
//{
//	const int CLIENTS = 4;
//	using namespace std;
//
//	Brass* p_clients[CLIENTS];
//	std::string temp;
//	long tempnum;
//	double tempbal;
//	char kind;
//
//	for (int i = 0; i < CLIENTS; i++)
//	{
//		cout << "Enter client's name:";
//		getline(cin, temp);
//		cout << "Enter client's account number:";
//		cin >> tempnum;
//		cout << "Enter opening balance:$";
//		cin >> tempbal;
//		cout << "Enter 1 for Brass Account or 2 for BrassPlus Account:";
//		while (cin >> kind && (kind != '1' && kind != '2'))
//			cout << "Enter either 1 or 2:";
//		if (kind == '1')
//			p_clients[i] = new Brass(temp, tempnum, tempbal);
//		else
//		{
//			double tmax, trate;
//			cout << "Enter the overdraft limit:$";
//			cin >> tmax;
//			cout << "Enter the interest rate as a decimal fraction:";
//			cin >> trate;
//			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
//		}
//		while (cin.get() != '\n')
//			continue;
//	}
//	cout << endl;
//	for (int i = 0; i < CLIENTS; i++)
//	{
//		p_clients[i]->ViewAcct();
//		cout << endl;
//	}
//
//	for (int i = 0; i < CLIENTS; i++)
//	{
//		delete p_clients[i];
//	}
//	cout << "Done.\n";
//}

void usebrass3()
{
	const int CLIENTS = 4;
	using namespace std;

	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name:";
		getline(cin, temp);
		cout << "Enter client's account number:";
		cin >> tempnum;
		cout << "Enter opening balance:$";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or 2 for BrassPlus Account:";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2:";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit:$";
			cin >> tmax;
			cout << "Enter the interest rate as a decimal fraction:";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	cout << "Done.\n";
}

void usedma()
{
	using namespace std;

	baseDMA shirt("Portablely", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "Displaying baseDMA object:\n";
	cout << shirt << endl;
	cout << "Displaying lacksDMA object:\n";
	cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "result of lacksDMA copy:\n";
	cout << balloon2 << endl;
	hasDMA map2;//初始化（默认构造函数）
	map2 = map;//赋值（赋值运算符）
	cout << "Result of hasDMA assignment:\n";
	cout << map2 << endl;

	cout << endl << "Shirt:\n";
	balloon.View();
	cout << endl << "Map:\n";
	map.View();
	cout << endl << "Balloon2:\n";
	balloon2.View();
	cout << endl << "Map2:\n";
	map2.View();
}

void Bravo(const Cd& disk)
{
	disk.Report();
}

void Practice01()
{
	using namespace std;
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd* pcd = &c1;
	cout << "**********************\n";
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "**********************\n";
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "**********************\n";
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "**********************\n";
	cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	copy.Report();
}

void Practice04()
{
	Port wine1("Leonardo", "white", 15);
	Port wine2 = wine1;
	cout << "Now your wines are:\n";
	wine1.Show();
	wine2.Show();
	wine1 += 18;
	wine2 -= 6;
	cout << "After the change, your wines' bottles are:\n";
	cout << "Wine1: ";
	wine1.BottleCount();
	cout << "Wine2: ";
	wine2.BottleCount();
	cout << "And the conclusion is\n";
	cout << wine1 << endl;
	cout << wine2 << endl;
	cout << endl;
	cout << "Now your wines upgrade to VintagePort class.\n";
	VintagePort wine3("Elma", 21, "tww", 23);
	VintagePort wine4;
	(Port&)wine4 = (Port&)wine3;
	(VintagePort&)wine4 = (VintagePort&)wine3;
	cout << "Now the new wines are:\n";
	wine3.Show();
	wine4.Show();
	wine3 += 17;
	wine4 -= 5;
	cout << "After the change, your new wines' bottles are:\n";
	cout << "Wine3: ";
	wine3.BottleCount();
	cout << "Wine4: ";
	wine4.BottleCount();
	cout << "And the conclusion is\n";
	cout << wine3 << endl;
	cout << wine4 << endl;
	cout << endl;
}