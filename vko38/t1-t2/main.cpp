#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

int main()
{
	Paivays tanaan; // tanaan olio luodaan Paivays-luokasta
	tanaan.tulosta();

	Paivays huomenna(31, 12, 2017);
	huomenna.tulosta();
	huomenna.lisaaPaiva();
	huomenna.montakoPaivaaKuukaudessa();
	huomenna.tulosta();

	return 0;
}
