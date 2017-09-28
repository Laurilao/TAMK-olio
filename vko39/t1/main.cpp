#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

int main()
{
	Paivays tanaan;
	Paivays huomenna(29, 9, 2017);
	Paivays ylihuomenna(huomenna);

	tanaan.tulosta();
	huomenna.tulosta();
	ylihuomenna.tulosta();

	ylihuomenna.lisaaPaiva();
	ylihuomenna.tulosta();


	system("pause");
	return 0;
}