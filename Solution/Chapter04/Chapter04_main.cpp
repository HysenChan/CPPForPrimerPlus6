#include"Chapter04_main.h"

using namespace std;

int main()
{
	//ArrayOne();
	//StringBase();
	//InStr1Cpp();
	//NumStr();
	//StrType();
	//StrType2();
	//StrType3();
	//StrType4();
	//StrType5();
	//Structur();
	//Arrstructur();
	//Union();
	//smallStore();
	//Enumerate();
	//Address();
	//Pointer();
	//InitPtr();
	//UseNew();
	//InitPtrArray();
	//ArrayNew();
	PointerSummary();
	return 0;
}

void ArrayOne()
{
	int yams[3];
	yams[0] = 1;
	yams[1] = 2;
	yams[2] = 3;

	int yamcosts[3] = { 20,30,5 };

	cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs " << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";
	int elementNum = sizeof yamcosts / sizeof(int);
	cout << "The element num of yamcosts is " << elementNum << ".\n";

	cout << "\nSize of yams array = " << sizeof yams << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";
}

void StringBase()
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "B:	Hi,I'm " << name2 << ",What's your name?\n";
	cin >> name1;
	cout << "A:	My name is " << name1 << ",has " << strlen(name1) << " letters and is stored in an array of " << sizeof(name1) << " bytes.\n";
	cout << "B:	Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';
	cout << "A:	Here are the first 3 character of my name:" << name2 << endl;
}

void InStr1Cpp()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	//cin >> name;
	//cin.getline(name, ArSize);
	cin.get(name, ArSize).get();
	cout << "Enter your favorite dessert:\n";
	//cin >> dessert;
	//cin.getline(dessert, ArSize);
	//cin.get(dessert, ArSize);
	//cin.getline(name, ArSize).getline(dessert, ArSize);
	cin.get(dessert, ArSize).get();
	cout << "I have some delicious " << dessert << " for you," << name << ".\n";
}

void NumStr()
{
	cout << "What year was your house built?\n";
	int year;
	//cin >> year;//会导致地址没办法输入，需要先摒弃换行符'\n'
	(cin >> year).get();
	cout << "What is its stree address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built:" << year << " and address is " << address << endl;
}

void StrType()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	//define in c++11
	char first_data[] = { "Le Chapon Dodu" };
	char second_data[]{ "The elegant Plate" };
	string third_data = { "The Bread Bowl" };
	string fourth_data{ "Hank's Fine Eates" };

	cout << "Enter a kind of feline:";
	cin >> charr1;
	cout << "Enter another kind of feline:";
	cin >> str1;
	cout << "Here are some felines;\n" << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
	cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;
}

void StrType2()
{
	string s1 = "penguin";
	string s2, s3;

	cout << "You can assign one string object to another: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ",s2:" << s2 << endl;
	cout << "s2 = 'buzzard'\n";
	s2 = "buzzard";
	cout << "s2:" << s2 << endl;
	s3 = s1 + s2;
	cout << "s3=s1+s2:" << s3 << endl;
	s1 += s3;
	cout << "s1+=s3:" << s1 << endl;
}

void StrType3()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy_s(charr1, charr2);
	cout << "after copy charr1:" << charr1 << endl;
	cout << "after copy charr2:" << charr2 << endl;

	str1 += "paste";
	strcat_s(charr1, " juice");
	cout << "str1:" << str1 << endl;
	cout << "charr1:" << charr1 << endl;

	size_t  len1 = str1.size();
	size_t  len2 = strlen(charr1);

	cout << "len1:" << len1 << endl;
	cout << "len2:" << len2 << endl;
}

void StrType4()
{
	char charr[20] = { '\0' };
	string str;

	cout << "Length of charr:" << strlen(charr) << endl;//unsafe;-> use '\0' to initialize charr array
	cout << "Length of str:" << str.size() << endl;

	cout << "Enter a line to charr:";
	cin.getline(charr, 20);
	cout << "Enter a line to str:";
	getline(cin, str);
	cout << "After enter line,charr length is:" << strlen(charr) << " str length is:" << str.size() << endl;
	cout << "charr:" << charr << '\t' << "str:" << str << endl;
}

void StrType5()
{
	wchar_t title[] = L"Chief Astrogator";//w_char string
	char16_t name[] = u"Felonia Ripova";//char_16 string
	char32_t car[] = U"Humber Super Snipe";//char_32 string

	cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';//Jim "King" Tutt uses "\n" instead of endl.
	cout << R"(Hysen\b\n\tChan)" << endl;//Hysen\b\n\tChan
	cout << R"+*(Hello World)+*" << endl;//Hello World
	cout << R"^(Oh no)^" << endl;//Oh no
	cout << R".*(Oh no).*" << endl;//Oh no
}

struct inflatable
{
	char name[20];
	float volume;
	double price;
};
struct
{
	int x;
	int y;
}position;
void Structur()
{
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99,
	};

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99,
	};

	cout << "Expand your guest list with " << guest.name << " and " << pal.name << ".\n";
	cout << "You can have both for $" << guest.price + pal.price << "!\n";
	cout << "pal.name[0]:" << pal.name[0] << endl;//A

	position.x = 10;
	position.y = 20;
	cout << "Position:" << position.x << "," << position.y << endl;
}

struct torgle_register
{
	unsigned int SN : 4;
	unsigned int : 4;
	bool goodIn : 1;
	bool goodTorgle : 1;
};

void Arrstructur()
{
	inflatable guests[2] =
	{
		{"Bambi",0.5,21.99},
		{"Godzilla",2000,565.99},
	};

	cout << "guests[0].name:" << guests[0].name << ends << "guests[1].name:" << guests[1].name << endl;
	cout << "guests[0[.volume:" << guests[0].volume << ends << "guests[1].volume:" << guests[1].volume << endl;
	cout << "guests[0[.price:" << guests[0].price << ends << "guests[1].price:" << guests[1].price << endl;

	torgle_register tr = { 14,true,false };

	if (tr.goodIn)
	{
		cout << "goodIn:" << tr.goodIn << endl;
	}
}

union one4all
{
	int int_val;
	long long_val;
	double double_val;
};
void Union()
{
	one4all pail;
	pail.int_val = 10;
	cout << pail.int_val << endl;
	pail.double_val = 12.123;
	cout << pail.double_val << endl;
	cout << pail.int_val << endl;//double.val被赋值了，int_val会被丢弃
}

struct widget
{
	char brand[20];
	int type;
	union
	{
		long id_num;
		char id_char[20];
	}id_val;
};
void smallStore()
{
	widget price;
	cout << "Pls enter price's type:";
	cin >> price.type;
	cout << "Pls enter price's id:";
	if (price.type == 1)
	{
		cin >> price.id_val.id_num;
		cout << "price.id_val.id_num:" << price.id_val.id_num;
	}
	else
	{
		cin >> price.id_val.id_char;
		cout << "price.id_val.id_char:" << price.id_val.id_char;
	}
}

enum spectrum
{
	red, orange, yellow, green, blue, voilet, indigo, ultraviolet
};
void Enumerate()
{
	spectrum band;

	band = blue;

	band = orange;
	cout << "band:" << band << endl;

	int color = blue;
	cout << "color1:" << color << endl;
	color = 3 + red;
	cout << "color2:" << color << endl;
}

void Address()
{
	int donuts = 1;
	double cups = 1.2;

	cout << "donuts value:" << donuts << " and address is:" << &donuts << endl;
	cout << "cups value:" << cups << " and address is:" << &cups << endl;
}

void Pointer()
{
	int updates = 6;
	int* p_updates;
	p_updates = &updates;

	//Two Value
	cout << "Values: updates = " << updates << endl;
	cout << "*p_updates = " << *p_updates << endl;

	//Two Address
	cout << "Addresses: updates = " << &updates << endl;
	cout << "p_updates = " << p_updates << endl;

	//Use pointer to change value
	*p_updates = *p_updates + 1;
	cout << "Now *p_updates = " << *p_updates << endl;
	cout << "updates = " << updates << endl;
}

void InitPtr()
{
	int higgens = 5;
	int* pt = &higgens;

	cout << "Value of higgens = " << higgens << "; Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt << ";Value of pt = " << pt << endl;
}

void UseNew()
{
	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	cout << "night value = " << nights << ":location = " << &nights << endl;
	cout << "int value = " << *pt << ":location = " << pt << endl;

	double* pd = new double;
	*pd = 10000001.0;

	cout << "double value = " << *pd << ":location = " << pd << endl;
	cout << "location of pointer pd:" << &pd << endl;
	cout << "size of pt = " << sizeof(pt) << ":size of *pt = " << sizeof(*pt) << endl;//64bits->address:8 value:4
	cout << "size of pd = " << sizeof(pd) << ":size of *pd = " << sizeof(*pd) << endl;//64bits->address:8 value:4
	delete pt;
	delete pd;
}

void InitPtrArray()
{
	int* psome = new int[10];//create array by ptr;
	delete[] psome;//release ptr;
}

void ArrayNew()
{
	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[1] << endl;//0.5
	p3 = p3 + 1;//p3指针默认是从0开始，+1之后变成指向了p3[1]
	cout << "Now p3[0] is " << p3[0] << endl;//0.5
	cout << "p3[1] is " << p3[1] << endl;//0.8
	p3 = p3 - 1;//还原指向p3[0]
	delete[] p3;
}

void PointerSummary()
{
	short tell[10];
	cout << tell << endl;
	cout << &tell << endl;

	double* pn;
	double* pa;
	char* pc;
	double bubble = 3.2;
	pn = &bubble;
	pc = new char;
	pa = new double[30];

	cout << "*pn:" << *pn << ",address:" << pn << endl;
	*pc = 'S';
	cout << "*pc:" << *pc << ",address:" << pc << endl;

	//区分指针和指针所指向的值
	int* pt = new int;
	*pt = 5;
	cout << "*pt:" << *pt << ",address:" << pt << endl;

	//指针算术
	int tacos[10] = { 5,2,8,4,1,2,2,4,6,8 };
	int* pb = tacos;
	pb = pb + 1;
	int* pe = &tacos[9];
	pe = pe - 1;
	int diff = pe - pb;//tacos[8]-tacos[1] = 7（相差7)
	cout << "*pb:" << *pb << "\t" << "*pe:" << *pe << endl;
	cout << "pe:" << pe << "\t" << "pb:" << pb << endl;
	cout << "diff:" << diff << endl;

	//数组的动态联编和静态联编
	int staticSize[10];//静态联编

	int size = 10;
	//cin >> size;
	int* pz = new int[size];//动态联编

	delete[] pz;

	//数组表示法和指针表示法
	int* ph = new int[10];
	*ph = 5;
	cout << "*ph:" << *ph << endl;
	ph[0] = 6;
	cout << "ph[0]:" << ph[0] << endl;
	cout << "ph[2]" << ph[2] << endl;
	ph[9] = 44;
	cout << "ph[9]:" << ph[9] << endl;
	int coats[10];
	*(coats + 4) = 12;
	cout << "coats[4]:" << coats[4];
}
