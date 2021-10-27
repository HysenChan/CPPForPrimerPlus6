#include"golf.h"
#include "practice.h"

int main()
{
	Practice01();
	return 0;
}

void Practice01()
{
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);

	/*golf andy;
	setgolf(andy);
	showgolf(andy);*/

	golf g[3];
	int i = 0;
	while ((i < 3) && (setgolf(g[i])))
	{
		showgolf(g[i]);
		std::cout << "Next golf:\n";
		i++;
	}
}
