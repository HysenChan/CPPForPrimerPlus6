#include"Chapter10_main.h"
#include"stock00.h"

int main()
{
	useStock0();
	return 0;
}

void useStock0()
{
	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("NanoSmatrt", 20, 12.50);
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
