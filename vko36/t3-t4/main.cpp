#include <iostream>
#include <Windows.h>

#include "Kello.h"

using std::cout; using std::endl; using std::cin;

int main()
{
	Kello rolex;

	rolex.asetaAika(14, 49, 12);

	rolex.annaTunnit();
	rolex.annaMinuutit();
	rolex.annaSekunnit();

	while (true)
	{
		rolex.tulosta();
		rolex.lisaaSekunti();
		Sleep(1000);
	}

	system("pause");
	return 0;
}