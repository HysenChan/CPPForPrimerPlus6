#include<new>
struct chaff
{
	char dross[20];
	int slag;
};

char buffer1[50];
char buffer2[500];

int mainUseNew()
{
	chaff* p1, * p2;
	int* p3, * p4;

	p1 = new chaff;
	p3 = new int[20];

	p2 = new(buffer1) chaff;
	p4 = new(buffer2) int[20];
	return 0;
}