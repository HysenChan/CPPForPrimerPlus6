#pragma once

#include<string>

class Worker
{
public:
	Worker() :fullname("no one"), id(0L) {}
	Worker(const std::string& s, long n) :fullname(s), id(n) {}
	virtual~Worker() = 0;
	virtual void Set();
	virtual void Show() const;

private:
	std::string fullname;
	long id;
};

class Waiter :public Worker
{
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const std::string& s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) :Worker(wk), panache(p) {}
	void Set();
	void Show() const;

private:
	int panache;
};

class Singer :public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
public:
	Singer() :Worker(), voice(other) {}
	Singer(const std::string& s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) :Worker(wk), voice(v) {}
	void Set();
	void Show()const;

private:
	static const char* pv[Vtypes];
	int voice;
};

