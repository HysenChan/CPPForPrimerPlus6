#include"practice05.h"


Stacks::Stacks()
{
	top = 0;
}

bool Stacks::isempty() const
{
	return top == 0;
}

bool Stacks::isfull() const
{
	return top == 3;
}

bool Stacks::push(const Items& item)
{
	if (top < 3)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stacks::pop(Items& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

void Stacks::showStacks() const
{
	if (!isempty())
	{
		std::cout << items[top - 1].fullname << "," << items[top - 1].payment << std::endl;
	}
}

Stacks::~Stacks()
{
}