#include<iostream>
#include<cmath>
#include"coordin.h"

polar rect_to_polar(rect xyPos)
{
	using namespace std;
	polar answer;

	answer.distance = sqrt(xyPos.x * xyPos.x + xyPos.y * xyPos.y);
	answer.angle = atan2(xyPos.y, xyPos.x);
	return answer;
}

void show_polar(polar daPos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;
	cout << "Distance = " << daPos.distance;
	cout << ",Angle = " << daPos.angle * Rad_to_deg;
	cout << " degress.\n";
}