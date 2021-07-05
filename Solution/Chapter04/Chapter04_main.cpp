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
	Union();
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
