#pragma once
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode
		{
			RECT,
			POL,
		};
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xVal() const { return x; }
		double yVal() const { return y; }
		double magVal() const { return mag; }
		double angVal() const { return ang; }
		void polar_mode();
		void rect_mode();

		//operator overloading
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;

		//friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;

		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	};
}