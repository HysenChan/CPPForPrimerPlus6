#include"chapter11_main.h"
#include"chapter11_vector.h"

int main()
{
	Randwark();
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
	fstream fout;
	fout.open("thewalk.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit):";
	while (cin >> target)
	{
		cout << "Enter step length:";
		if (!(cin >> dstep))
			break;

		while (result.magVal() < target)
		{
			direction = rand() % 20;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the floowing location:\n";
		cout << result << endl;
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