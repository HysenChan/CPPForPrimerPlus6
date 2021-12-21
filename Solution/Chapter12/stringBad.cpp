#include"stringBad.h"

int StringBad::num_strings = 0;

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "c++");
	num_strings++;
	std::cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

StringBad::~StringBad()
{
	using std::cout;
	cout << "\"" << str << "\" object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
