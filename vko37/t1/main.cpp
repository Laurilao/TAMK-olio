#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

int main()
{
	Paivays tanaan; // tanaan olio luodaan Paivays-luokasta
	tanaan.tulosta();
	
	Paivays huomenna(15, 9, 2017);
	huomenna.tulosta();

	return 0;
}
