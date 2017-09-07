#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

int main()
{
	Paivays tanaan; // tanaan olio luodaan Paivays-luokasta

	tanaan.asetaPaiva(7);
	tanaan.asetaKuukausi(9);
	tanaan.asetaVuosi(2017);

	tanaan.tulosta();

	cout << tanaan.annaKuukausi() << "/" << tanaan.annaPaiva() << "/" << tanaan.annaVuosi() << endl;

	system("pause");
	return 0;
}