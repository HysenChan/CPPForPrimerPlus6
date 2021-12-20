#include"chapter11_vector.h"

#include<cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);

	double Vector::set_mag()
	{
		double mag;
		mag = sqrt(x * x + y * y);
		return mag;
	}

	double Vector::set_ang()
	{
		double ang;
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
		return ang;
	}

	void Vector::set_x(double mag, double ang)
	{
		x = mag * cos(ang);
	}
	void Vector::set_y(double mag, double ang)
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			double mag, ang;
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x(mag, ang);
			set_y(mag, ang);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			double mag, ang;
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x(mag, ang);
			set_y(mag, ang);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << "," << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m,a) = (" << v.magVal() << "," << v.angVal() * Rad_to_deg << ")";
		else
			os << "Vector object mode is invalid";
		return os;
	}
}