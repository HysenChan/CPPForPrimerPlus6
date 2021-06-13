#include<iostream>
#include<cmath>

using namespace std;

template<class T>
int getArrayLength(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

string Menu[] = {
	"Print personal info.",
	"Covert distance.",
	"Print str.",
	"Covert age to how month.",
	"Covert celsius to fahrenheit.",
	"Covert light years to astronomical units.",
	"Print enter hour and minute",
};

void CreateMenu()
{
	int menuLength = getArrayLength(Menu);
	cout << "选择菜单:" << endl;
	for (int i = 0; i < menuLength; i++)
	{
		cout << i + 1 << "." << Menu[i] << endl;
	}
}

//Answer Chapter02	P35
void personalInfo();
//2.7  01.
int convertDistance(int length);//2.7	02.
void displayString(string str);//2.7	03.
int convertAgeToMonth(int age);//2.7	04.
float convertCelsiusToFahrenheit(float celsius);//2.7	05.
double convertLightYearsToAstrUnits(double lYears);//2.7	06.
int displayTime(int hour, int min);//2.7	07.

void ChooseStep()
{
	int enterNum = 1;
	while (enterNum != 0)
	{
		cout << "输入对于数字进行对应操作( 0 退出):" << ends;
		cin >> enterNum;
		switch (enterNum)
		{
		case 1:
		{
			personalInfo();//01.
			break;
		}
		case 2:
		{
			int curYard = convertDistance(10);//02.
			cout << "转换完成后为：" << curYard << "码" << endl;
			break;
		}
		case 3:
		{
			string str1 = "Three blind mice";//03.
			string str2 = "See how they run";
			displayString(str1);
			displayString(str1);
			displayString(str2);
			displayString(str2);
			break;
		}
		case 4:
		{
			cout << "输入年龄:" << ends;//04.
			int age;
			cin >> age;
			int month = convertAgeToMonth(age);
			cout << "该年龄包含" << month << "个月" << endl;
			break;
		}
		case 5:
		{
			cout << "输入摄氏度:" << ends;//05.
			int celsius;
			cin >> celsius;
			float fahrenheit = convertCelsiusToFahrenheit(celsius);
			cout << "摄氏度:" << celsius << " " << "华氏度:" << fahrenheit << endl;
			break;
		}
		case 6:
		{
			cout << "输入光年:" << ends;//06.
			int lYears;
			cin >> lYears;
			float astrUnits = convertLightYearsToAstrUnits(lYears);
			cout << "光年:" << lYears << " " << "天文单位:" << astrUnits << endl;
			break;
		}
		case 7:
		{
			int hour, minute;
			cout << "输入小时:" << ends;//07.
			cin >> hour;
			cout << "输入分钟:" << ends;
			cin >> minute;
			displayTime(hour, minute);
			break;
		}
		default:
			if (enterNum == 0) return;
			cout << "无此操作！" << endl;
			CreateMenu();
			break;
		}
	}
}

int main()
{
	CreateMenu();
	ChooseStep();
	return 0;
}

void personalInfo()
{
	string name = "HysenChan";
	string address = "China";
	cout << name << ends << address << endl;
}

int convertDistance(int length)
{
	int yard = length * 220;
	return yard;
}

void displayString(string str)
{
	cout << str << endl;
}

int convertAgeToMonth(int age)
{
	int month = age * 12;
	return month;
}

float convertCelsiusToFahrenheit(float celsius)
{
	float fahrenheit = celsius * 1.8 + 32.0;
	return fahrenheit;
}

double convertLightYearsToAstrUnits(double lYears)
{
	double astrUnits = lYears * 63240;
	return astrUnits;
}

int displayTime(int hour, int min)
{
	cout << "Time:" << hour << ":" << min << endl;
	return 0;
}