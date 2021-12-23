#include"stringOfficial.h"

int String::num_strings = 0;

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';

	//len = 0;
	//str = 0;//str = nullptr;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

int String::HowMany()
{
	return num_strings;
}

String::~String()
{
	--num_strings;
	delete[] str;
}

bool operator<(const String& st, const String& st2)
{
	return (std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String& st, const String& st2)
{
	return st2 < st;
}

bool operator==(const String& st, const String& st2)
{
	return (std::strcmp(st.str, st2.str) == 0);
}

std::istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}
