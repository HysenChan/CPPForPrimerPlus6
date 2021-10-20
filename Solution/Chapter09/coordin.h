#ifndef COORDIN_H_
#define COORDIN_H_H

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

polar rect_to_polar(rect xyPos);
void show_polar(polar daPos);

#endif // !COORDIN_H_

