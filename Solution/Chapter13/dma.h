#pragma once
#pragma warning(disable : 4996)
#include<iostream>

class baseDMA
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);

private:
	char* label;
	int rating;
};

class lacksDMA :public baseDMA
{
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);

private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
};

class hasDMA :public baseDMA
{
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);

private:
	char* style;
};
