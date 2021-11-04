#include"Chapter10_main.h"
#include"stock10.h"

int main()
{
	useStock1();
	//useStock0();
	return 0;
}

void useStock0()
{
	//Stock fluffy_the_cat;//默认构造函数
	//Stock* fluffy_the_cat = new Stock("Furry Mason", 50, 2.5);
	Stock fluffy_the_cat("Furry Mason", 50, 2.5);//Stock fluffy_the_cat = Stock("Furry Mason", 50, 2.5);
	//fluffy_the_cat.acquire("NanoSmatrt", 20, 12.50);
	//Stock fluffy_the_cat{ "Furry Mason", 50, 2.5 };//C++11
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(300000, 40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(300000, 0.125);
	fluffy_the_cat.show();
}

void useStock1()
{
	const int STK = 4;
	Stock stocks[STK] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5),
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STK; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];
	for (st = 0; st < STK; st++)
		top = &top->topval(stocks[st]);

	std::cout << "\nMost valuable holding:\n";
	top->show();
}
