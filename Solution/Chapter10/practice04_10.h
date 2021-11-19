#pragma once
#include<iostream>

namespace SALES_TEN
{
	const int QUARTERS = 4;
	class Sale
	{
	public:
		Sale();
		void setSale();
		void setSale(const double ar[], int n);
		void showSale()const;
		~Sale();

	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
}