#pragma once

#include <iostream>
#include <valarray>
#include <string>
using namespace std;

///Practice01 && Practice02
template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	void set(const T1& yr, const T2& bot);
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {}
	int Sum() const;
	void Show(int y) const;
	~Pair();
};

template <class T1, class T2>
void Pair<T1, T2>::set(const T1& yr, const T2& bot)
{
	a = yr;
	b = bot;
}

template <class T1, class T2>
int Pair<T1, T2>::Sum() const
{
	return b.sum();
}

template <class T1, class T2>
void Pair<T1, T2>::Show(int y) const
{
	for (int i = 0; i < y; i++)
	{
		std::cout << "\t\t" << a[i] << "\t\t" << b[i] << std::endl;
	}
}

template<class T1, class T2>
inline Pair<T1, T2>::~Pair()
{
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine :private std::string, private PairArray
{
private:
	int yrs;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	std::string& Label();
	int sum();
	void Show();
	~Wine();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : std::string(l), yrs(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char* l, int y) : std::string(l), yrs(y)
{
}

void Wine::GetBottles()
{
	ArrayInt yr(yrs), bot(yrs);
	std::cout << "Enter " << (const std::string&)*this << " data for " << yrs << " year(s):\n";
	for (int i = 0; i < yrs; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> yr[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> bot[i];
	}
	PairArray::set(yr, bot);
}

std::string& Wine::Label()
{
	return (std::string&)*this;
}

int Wine::sum()
{
	return PairArray::Sum();
}

void Wine::Show()
{
	std::cout << "Wine: " << (const std::string&)*this << std::endl;
	std::cout << "\t\tYear\tBottles\n";
	PairArray::Show(yrs);
}

inline Wine::~Wine()
{
}

///Practice03

template<class T>
class QueueTP
{
public:
	QueueTP(int qs = Q_SIZE);
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const T& item);
	bool dequeue(T& item);
	~QueueTP();

private:
	struct Node
	{
		T item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP& q) :qsize(0) {}
	QueueTP& operator = (const QueueTP& q) { return *this; }
};

template<class T>
QueueTP<T>::QueueTP(int qs) :qsize(qs)
{
	items = 0;
	front = rear = NULL;
}

template<class T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class T>
bool QueueTP<T>::isempty()const
{
	return items == 0;
}

template<class T>
bool QueueTP<T>::isfull()const
{
	return items == qsize;
}

template<class T>
int QueueTP<T>::queuecount()const
{
	return items;
}

template<class T>
bool QueueTP<T>::enqueue(const T& item)
{
	if (isfull())
	{
		cout << "Queue already full!\n";
		return false;
	}
	Node* newitem = new Node;
	newitem->item = item;
	newitem->next = NULL;
	items++;
	if (front == NULL)
		front = newitem;
	else
		rear->next = newitem;
	rear = newitem;
	return true;
}

template<class T>
bool QueueTP<T>::dequeue(T& item)
{
	if (isempty())
	{
		cout << "It's empty now!\n";
		return false;
	}
	else
	{
		item = front->item;
		items--;
		Node* temp = front;
		front = front->next;
		delete temp;
		if (items == 0)
		{
			rear = NULL;
		}
	}
	return true;
}

class Worker
{
public:
	Worker() :fullname("no one"), id(0L) {}
	Worker(const string& s, long n) :fullname(s), id(n) {}
	virtual ~Worker();
	virtual void Set();
	virtual void Show()const;

private:
	string fullname;
	long id;
};

void Worker::Set()
{
	cout << "Enter worker's name:";
	getline(cin, fullname);
	cout << "Enter worker's ID:";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Show()const
{
	cout << "Name:" << fullname << endl;
	cout << "Employee ID:" << id << endl;
}

Worker::~Worker()
{

}

///Practice04
class Person
{
public:
	Person() :firstname("None"), lastname("None") {}
	Person(string fname, string lname) :firstname(fname), lastname(lname) {}
	Person(const Person& p);
	virtual ~Person() = 0;
	virtual void Show()const = 0 { cout << "Firstname:" << firstname << "\nLastname:" << lastname << endl; }

private:
	string firstname;
	string lastname;
};

class Gunslinger :virtual public Person
{
public:
	Gunslinger(int n = 0, double t = 0) :Person(), nick(n), time(t) {}
	Gunslinger(const string fname, const string lname, int n, double t) :Person(fname, lname), nick(n), time(t) {}
	Gunslinger(const Person& p, int n, double t = 0) :Person(p), nick(n), time(t) {}
	Gunslinger(const Gunslinger& g);
	~Gunslinger();
	double Draw()const;
	void Show()const;

private:
	int nick;
	double time;
};

class PokerPlayer :virtual public Person
{
public:
	int Draw() const;
	void Show()const;
	PokerPlayer() :Person() {}
	PokerPlayer(const string fname, const string lname) :Person(fname, lname) {}
	PokerPlayer(const Person& p) :Person(p) {}
	PokerPlayer(const PokerPlayer& p) :Person(p) {}
	~PokerPlayer();

};

class BadDude :public Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(const string fname, const string lname, int n, double t) : Person(fname, lname), Gunslinger(fname, lname, n, t), PokerPlayer(fname, lname) {}
	BadDude(const Person& p, int n, double t) : Person(p), Gunslinger(p, n, t), PokerPlayer(p) {}
	BadDude(const Gunslinger& g, int n, double t) : Person(g), Gunslinger(g, n, t), PokerPlayer(g) {}
	BadDude(const PokerPlayer& p, int n, double t) : Person(p), Gunslinger(p, n, t), PokerPlayer(p) {}
	~BadDude();
	void Show() const;
	double Gdraw();
	int Cdraw();

};

Person::Person(const Person& p)
{
	firstname = p.firstname;
	lastname = p.lastname;
}

Person::~Person()
{
}

Gunslinger::Gunslinger(const Gunslinger& g) : Person(g)
{
	nick = g.nick;
	time = g.time;
}

double Gunslinger::Draw() const
{
	return time;
}

void Gunslinger::Show() const
{
	cout << "Category: Gunslinger\n";
	Person::Show();
	cout << "Nicks: " << nick << ", Gun out time: " << time << endl;
}

Gunslinger::~Gunslinger()
{
}

int PokerPlayer::Draw() const
{
	return (rand() % 52);
}

void PokerPlayer::Show() const
{
	cout << "Category: PokerPlayer\n";
	Person::Show();
}

PokerPlayer::~PokerPlayer()
{
}

void BadDude::Show() const
{
	cout << "Category: Bad Dude\n";
	Gunslinger::Show();
	cout << "Next card: " << PokerPlayer::Draw() << endl;
}

double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

BadDude::~BadDude()
{
}