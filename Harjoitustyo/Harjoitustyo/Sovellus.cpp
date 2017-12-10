#include "Sovellus.h"
#include <iostream>

using std::endl; using std::cout; using std::cin; using std::getline;

Sovellus::Sovellus()
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::aja()
{
	Koulu koulu = Koulu("Superkoulu");
	string nro;

	do
	{
		nro = Sovellus::tulostaValikko();

		// Tarkista syotteen pituus, vain 1 tai 2 merkkia sallittu pituus
		while (nro.length() > 2)
		{
			cout << "Virheellinen syote, yrita uudelleen" << endl;
			nro = Sovellus::tulostaValikko();
		}

		if (nro == "1")
		{
			koulu.lisaaKoulutusohjelma();
		}
		else if (nro == "2")
		{
			koulu.tulostaKoulutusohjelmat();
		}
		else if (nro == "3")
		{
			koulu.tulostaKoulutusohjelmienMaara();
		}
		else if (nro == "4")
		{
			koulu.lisaaKoulutusohjelmaanOpettaja();
		}
		else if (nro == "5")
		{
			koulu.tulostaKoulutusohjelmanOpettajat();
		}
		else if (nro == "6")
		{
			koulu.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if (nro == "7")
		{
			koulu.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if (nro == "8")
		{
			koulu.poistaKoulutusohjelma();
		}
		else if (nro == "9")
		{
			koulu.poistaKoulutusohjelmanOpettaja();
		}
		else if (nro == "10")
		{
			koulu.poistaKoulutusohjelmanOpiskelija();
		}
		else if (nro == "11")
		{
			koulu.paivitaNimi();
		}
		else if (nro == "12")
		{
			koulu.paivitaOpettajanTiedot();
		}
		else if (nro == "13")
		{
			koulu.paivitaOpiskelijanTiedot();
		}
		else if (nro == "14")
		{
			koulu.tuoTiedot();
		}
		else if (nro == "15")
		{
			koulu.vieTiedot();
		}
		else
			// Jos syote 1-2 merkkia, mutta ei vastaa valikkotoimintoja
			cout << "Virheellinen syote, yrita uudelleen" << endl;

	} while (nro != "0");

	return;
}

string Sovellus::tulostaValikko()
{
	string valinta;

	cout << endl;
	cout << "1) Lisaa koulutusohjelma" << endl;
	cout << "2) Tulosta koulutusohjelmien nimet" << endl;
	cout << "3) Tulosta koulutusohjelmien maara" << endl;
	cout << "4) Lisaa koulutusohjelmaan opettaja" << endl;
	cout << "5) Tulosta koulutusohjelman opettajat" << endl;
	cout << "6) Lisaa koulutusohjelmaan opiskelija" << endl;
	cout << "7) Tulosta koulutusohjelman opiskelijat" << endl;
	cout << "8) Poista koulutusohjelma" << endl;
	cout << "9) Poista opettaja" << endl;
	cout << "10) Poista opiskelija" << endl;
	cout << "11) Paivita koulutusohjelman nimi" << endl;
	cout << "12) Paivita opettajan tiedot" << endl;
	cout << "13) Paivita opiskelijan tiedot" << endl;
	cout << "14) Lue tiedot" << endl;
	cout << "15) Tallenna tiedot" << endl;
	cout << "0) Lopeta" << endl << endl;

	cout << "Valintasi: ";
	getline(cin, valinta);

	return valinta;
}
