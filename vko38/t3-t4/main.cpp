#include <iostream>
#include <string>

#include "Opiskelija.h"
#include "Opettaja.h"


int main()
{
	Opiskelija esimerkki;
	esimerkki.tulosta();

	Opiskelija olli(10, "olli", "laurila", "olli@olli.fi");
	olli.tulosta();

	Opettaja esim;
	esim.tulosta();

	system("pause");
	return 0;
}