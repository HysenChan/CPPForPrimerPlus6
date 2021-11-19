#include "practice04_10.h"

namespace SALES_TEN
{
	int length = 0;
	Sale::Sale()
	{
	}

	void Sale::setSale(const double ar[], int n)
	{
		double total = 0;
		double max = ar[0];
		double min = ar[0];
		for (int i = 0; i < n; i++)
		{
			sales[i] = ar[i];
			total += sales[i];
			length++;
		}
		for (int i = 1; i < n; i++)
		{
			if (sales[i] > max)
				max = sales[i];
			else if (sales[i] < min)
				min = sales[i];
		}
		max = max;
		min = min;
		average = total / n;
	}

	void Sale::setSale()
	{
		double total = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			std::cout << "Enter the sale[" << i + 1 << "]:";
			std::cin >> sales[i];
			length++;
		}
		for (int i = 0; i < length; i++)
		{
			average = total / length;
			max = sales[0];
			min = sales[0];
			if (sales[i] > max)
				max = sales[i];
			else if (sales[i] < min)
				min = sales[i];
		}
	}

	void Sale::showSale()const
	{
		if (length <= 0)
			return;
		for (int i = 0; i < length; i++)
			std::cout << "sale[" << i + 1 << "]:" << sales[i] << std::endl;
		std::cout << "average:" << average << ",max:" << max << ",min:" << min << std::endl;
	}

	SALES_TEN::Sale::~Sale()
	{
	}
}