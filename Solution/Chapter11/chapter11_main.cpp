#include"chapter11_main.h"
#include"chapter11_vector.h"
#include"stonewt.h"
#include"complex.h"

void StonewtDisplay(const Stonewt& st, int n);

int main()
{
	Practice07();
	//StonewtTest01();
	//StonewtTest();
	//Randwark();
	//UseTime0();
	return 0;
}

void UseTime0()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	//total = coding.sum(fixing);
	//total = coding.operator+(fixing);
	total = coding + fixing;

	cout << "total time = ";
	total.show();
	cout << endl;

	cout << "diff time = ";
	Time diff(1, 30);
	diff = total - diff;
	diff.show();
	cout << endl;

	cout << "mult time = ";
	Time mult;
	mult = diff * 0.5;
	mult.show();
	cout << endl;

	cout << "friend mult time = ";
	Time multFriend;
	multFriend = 0.5 * total;
	multFriend.show();
	cout << endl;

	cout << "friend operator()<<\n";
	cout << multFriend;

	cout << "friend os operator()<<\n";
	cout << "Trip time:" << multFriend << " (Tuesday)\n";
}

void Randwark()
{
	using namespace std;
	using VECTOR::Vector;
	//fstream fout;
	//fout.open("thewalk.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int N;
	int maxSteps, minSteps, sumSteps;
	minSteps = 0;
	maxSteps = 65535;
	sumSteps = 0;
	double aveSteps;
	cout << "How many times of test would you want:";
	cin >> N;
	cout << "\nEnter target distance:";
	cin >> target;
	cout << "Enter step length:";
	cin >> dstep;
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		while (result.magVal() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		sumSteps += steps;
		if (steps > maxSteps)
			maxSteps = steps;
		if (steps < minSteps)
			minSteps = steps;
		steps = 0;
		result.reset(0.0, 0.0);
	}
	aveSteps = sumSteps / N;
	cout << "Walk finished!\nAfter " << N << " time of test , the result is following:\n";
	cout << "The maxnum steps is " << maxSteps << " the minnum stpes is " << minSteps << " averSteps:" << aveSteps;
	cout << "Bye!\n";
	cin.clear();
	ofstream fout;
	fout.open("RandWalk.txt");
	cout << "Enter target distance (q to quit):";
	while (cin >> target)
	{
		cout << "Enter step length:";
		if (!(cin >> dstep))
			break;
		else
			fout << "Target Distance:" << target << ", Step Size:" << dstep << endl;

		int i = 0;
		while (result.magVal() < target)
		{
			direction = rand() % 20;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			fout << i << ":(x,y) = (" << result.xVal() << "," << result.yVal() << ")\n";
			i++;
		}
		cout << "After " << steps << " steps, the subject has the floowing location:\n";
		cout << result << endl;
		fout << "After " << steps << " steps, the subject has the floowing location:\n";
		fout << result << endl;
		result.polar_mode();
		cout << " or \n" << result << endl;
		cout << "Average outward distance per step = " << result.magVal() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}

void StonewtTest()
{
	using std::cout;
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
	incognito.show_stn();

	cout << "The detective weighed ";
	wolfe.show_stn();

	cout << "The President weighed ";
	taft.show_lbs();

	incognito = 276.8;
	taft = 325;

	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();

	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	StonewtDisplay(taft, 2);
	cout << "The wrestler weighed even more.\n";
	StonewtDisplay(422, 2);
	cout << "No stone left unearned\n";
}

void StonewtTest01()
{
	using std::cout;
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int(poppins) << " pounds.\n";
}

void StonewtDisplay(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Wow!";
		st.show_stn();
	}
}

void Practice07()
{
	using namespace std;
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << "\n";
		cout << "complex conjugate is " << ~c << "\n";
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << "\n";
		cout << "a - c is " << a - c << "\n";
		cout << "a * c is " << a * c << "\n";
		cout << "2 * c is " << 2 * c << "\n";
		cout << "Enter a complex number (q to quit):\n";
	};
	cout << "Done!\n";
}