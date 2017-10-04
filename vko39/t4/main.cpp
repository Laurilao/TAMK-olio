#include <iostream>

#include "Kalenterimerkinta.h"

int main()
{
	Kalenterimerkinta km(Paivays(28, 9, 2017), Kello(10, 56, 12), "Kay kaupassa", true);
	Kalenterimerkinta km2;
	Kalenterimerkinta km3(km);

	km.tulostaMerkinta();
	km2.tulostaMerkinta();
	km3.tulostaMerkinta();

	km3.kysyTiedot();
	km3.tulostaMerkinta();


	system("pause");
	return 0;
}
