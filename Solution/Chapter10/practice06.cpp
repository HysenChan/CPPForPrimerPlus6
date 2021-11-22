#include"practice06.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showMove() const
{
	std::cout << "x:" << x << "," << "y:" << y << std::endl;
}

Move Move::add(const Move& m) const
{
	Move n;
	n.x = m.x + this->x;
	n.y = m.y + this->y;
	return n;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

Move::~Move()
{
}