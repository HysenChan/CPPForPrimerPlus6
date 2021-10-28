#include "practice04.h"

int length = 0;
void SALES::setSales(Sales& s, const double ar[], int n)
{
	double total = 0;
	double max = ar[0];
	double min = ar[0];
	for (int i = 0; i < n; i++)
	{
		s.sales[i] = ar[i];
		total += s.sales[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (s.sales[i] > max)
			max = s.sales[i];
		else if (s.sales[i] < min)
			min = s.sales[i];
	}
	s.max = max;
	s.min = min;
	s.average = total / n;
}

void SALES::setSales(Sales& s)
{
	double total = 0;
	for (int i = 0; i < QUARTERS; i++)
	{
		std::cout << "Enter the sale[" << i + 1 << "]:";
		std::cin >> s.sales[i];
	}
	for (int i = 0; i < length; i++)
	{
		s.average = total / length;
		s.max = s.sales[0];
		s.min = s.sales[0];
		if (s.sales[i] > s.max)
			s.max = s.sales[i];
		else if (s.sales[i] < s.min)
			s.min = s.sales[i];
	}
}

void SALES::showSales(const Sales& s)
{
	if (length <= 0)
		return;
	for (int i = 0; i < length; i++)
		std::cout << "s.sale[" << i + 1 << "]:" << s.sales[i] << std::endl;
	std::cout << "s.average:" << s.average << ",s.max:" << s.max << ",s.min:" << s.min << std::endl;
}
