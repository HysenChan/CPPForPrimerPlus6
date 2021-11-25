#include"chapter11_main.h"

int main()
{
	UseTime0();
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
}
