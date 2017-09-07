#include <iostream>
#include <Windows.h>

#include "Kello.h"

using std::cout; using std::endl;

int main()
{
	Kello rolex;

	rolex.asetaAika(23, 59, 59);
	while (true)
	{
		rolex.tulosta();
		rolex.lisaaSekunti();
		Sleep(1000);
	}

	system("pause");
	return 0;
}