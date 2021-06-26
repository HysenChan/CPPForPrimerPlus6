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
	StrType4();
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
