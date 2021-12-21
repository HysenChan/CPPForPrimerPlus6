#include"stringOfficial.h"

int String::num_strings = 0;

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
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

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
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

void operator>>(istream& is, String& st)
{
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}
