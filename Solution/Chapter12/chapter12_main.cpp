#include"chapter12_main.h"
#include"stringBad.h"
#include"stringOfficial.h"
#include"QueueTest.h"
#include"chapter12_practice01.h"

const int ArSize = 10;
const int MaxLen = 81;
const int BUF = 512;
const int MIN_PER_HR = 60;

int main()
{
	Practice01();
	//bank();
	//placenew1();
	//sayings();
	//vegnews1();
	//vegnews();
	return 0;
}

void callme1(StringBad& rsb)
{
	using std::cout;
	cout << "String psssed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad vsb)
{
	using std::cout;
	cout << "String psssed by value:\n";
	cout << "    \"" << vsb << "\"\n";
}

void vegnews()
{
	using std::cout;
	using std::endl;
	cout << "Starting an inner block.\n";
	StringBad headline1("AAAAA");
	StringBad headline2("BBBBB");
	StringBad sports("CCCCC");

	cout << "headline1:" << headline1 << endl;
	cout << "headline2:" << headline2 << endl;
	cout << "sports:" << sports << endl;
	callme1(headline1);
	cout << "headline1:" << headline1 << endl;
	callme2(headline2);
	cout << "headline2:" << headline2 << endl;
	cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	cout << "sailor:" << sailor << endl;
	cout << "Assign one object to another:\n";
	StringBad knot;
	knot = headline1;
	cout << "Knot:" << knot << endl;
	cout << "Exiting the block.\n";
}

void callme3(String& rsb)
{
	using std::cout;
	cout << "String psssed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme4(String vsb)
{
	using std::cout;
	cout << "String psssed by value:\n";
	cout << "    \"" << vsb << "\"\n";
}

void vegnews1()
{
	using std::cout;
	using std::cin;
	using std::endl;
	String opera("The Magic Flute");
	cout << opera[2] << endl;
	String means("might");
	means[0] = 'r';
	cout << means << endl;

	String text("Once upon a time");
	const String answer("futile");
	cout << text[1];
	cout << answer[1];
	cin >> text[1];
	//cin >> answer[1];
}

void sayings()
{
	using namespace std;
	String name;
	cout << "Hi, what's your name?\n>> ";
	cin >> name;

	cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ":";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
			//cout << sayings[i][0] << ":" << sayings[i] << endl;
			cout << sayings[i] << "\n";

		String* shortest = &sayings[0];
		String* first = &sayings[0];

		//int shortest = 0;
		//int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "No input!Bye.\n";
}

void placenew1()
{
	class JustTesting
	{
	public:
		JustTesting(const string& s = "Just Testing", int n = 0)
		{
			words = s;
			number = n;
			cout << words << " constructed\n";
		}
		~JustTesting()
		{
			cout << words << " destoryed\n";
		}
		void Show() const
		{
			cout << words << "," << number << endl;
		}

	private:
		string words;
		int number;
	};

	char* buffer = new char[BUF];

	JustTesting* pc1, * pc2;

	pc1 = new(buffer) JustTesting;
	pc2 = new JustTesting("Heap1", 20);

	cout << "Memory block addresses:\n" << "buffer:" << (void*)buffer << " heap:" << pc2 << endl;
	cout << "Memory contents:\n";
	cout << pc1 << ":";
	pc1->Show();
	cout << pc2 << ":";
	pc2->Show();

	JustTesting* pc3, * pc4;
	pc3 = new(buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ":";
	pc3->Show();
	cout << pc4 << ":";
	pc4->Show();

	delete pc2;
	delete pc4;
	pc3->~JustTesting();
	pc1->~JustTesting();
	delete[] buffer;
	cout << "Done.\n";
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}

void bank()
{
	using namespace std;
	srand(time(0));

	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;

	long cycleLimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour:";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cycleLimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	if (customers > 0)
	{
		cout << "customers accepted:" << customers << endl;
		cout << " customers served:" << served << endl;
		cout << " trunaways:" << turnaways << endl;
		cout << "average queue size:";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cycleLimit << endl;
		cout << " average wait time:" << (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
}

void Practice01()
{
	cout << "Let's start to see our cows!\n";
	Cow c1;
	c1.ShowCow();
	Cow c2("yellow", "eat grass", 123.456);
	c2.ShowCow();
	Cow c3("black", "Drink water", 111.222);
	c3.ShowCow();
	c3 = c1;
	c3.ShowCow();
	Cow c4(c2);
	c4.ShowCow();
}