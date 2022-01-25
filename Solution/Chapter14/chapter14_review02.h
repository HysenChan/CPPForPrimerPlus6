#pragma once
#include<iostream>
using namespace std;
class Frabjous
{
private:
	char fab[20];

public:
	Frabjous(const char* s = "C++") :fab(s) {}
	virtual void tell() { cout << fab; }
};

class Gloam
{
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);
	void tell();

private:
	int glip;
	Frabjous fb;
};

Gloam::Gloam(int g, const char* s) : glip(g), fb(s) {}

Gloam::Gloam(int g, const Frabjous& fr) : glip(g), fb(fr) {}

inline void Gloam::tell()
{
	fb.tell();
	cout << glip << endl;
}
