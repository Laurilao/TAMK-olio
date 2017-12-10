#include "Koulu.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::endl; using std::cout; using std::cin; using std::getline; using std::ifstream; using std::ofstream;
using std::istringstream;

Koulu::Koulu() : Koulutusohjelma(), nimi_()
{
}

Koulu::Koulu(string nimi) : Koulutusohjelma(), nimi_(nimi)
{
}

Koulu & Koulu::operator=(const Koulu & alkup)
{
	Koulutusohjelma::operator=(alkup);

	if (this != &alkup)
	{
		nimi_ = alkup.nimi_;

		for (int i = 0; i != koulutusohjelmat_.size(); i++)
		{
			koulutusohjelmat_[i] = alkup.koulutusohjelmat_[i];
		}
	}

	return *this;
}


Koulu::~Koulu()
{
}

string Koulu::annaNimi()
{
	return nimi_;
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

int Koulu::etsiKoulutusohjelma()
{
	/* Etsii koulutusohjelmat_ vektorista koulutusohjelmaa */

	string nimi;  // Apumuuttuja

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);

	// Selaa vektorin koulutusohjelmat
	for (int i = 0; i != koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_[i].annaNimi())
		{
			// Jos koulutusohjelma loytyi, palauta sen indeksi
			return i;
		}
	}
	// Jos ei loydy, palauta -1 ja ilmoita kayttajalle
	cout << "Koulutusohjelmaa ei loytynyt" << endl;
	return -1;
}

void Koulu::lisaaKoulutusohjelma()
{
	string ohjelma; // Apumuuttuja

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, ohjelma);

	// Koulutusohjelman nimen pituuden tarkastus
	if (ohjelma.length() < 2)
	{
		cout << "Koulutusohjelman oltava vahintaan 2 merkkia" << endl;
		return;
	}
	else
		koulutusohjelmat_.push_back(Koulutusohjelma(ohjelma));
}

void Koulu::poistaKoulutusohjelma()
{
	// Etsi koulutusohjelma-funktio
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + etsi);
		cout << "Koulutusohjelma poistettu" << endl;
	}
}

void Koulu::paivitaNimi()
{
	string uusi;  // Apumuuttuja

	// Etsi koulutusohjelma-funktio
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		do
		{
			cout << "Anna koulutusohjelman uusi nimi: ";
			getline(cin, uusi);

			if (uusi.length() >= 2)
			{
				koulutusohjelmat_[etsi].asetaNimi(uusi);
				cout << "Koulutusohjelman nimi paivitetty!" << endl;
			}
			else
				cout << "Koulutusohjelman nimi oltava vahintaan 2 merkkia" << endl;

		} while (uusi.length() < 2);

	}
}

void Koulu::tulostaKoulutusohjelmat()
{
	if (koulutusohjelmat_.size() != 0)
	{
		cout << "Koulutusohjelmat: " << endl;

		for (int i = 0; i != koulutusohjelmat_.size(); i++)
		{
			cout << koulutusohjelmat_[i].annaNimi() << endl;
		}
	}
	else
		cout << "Ei koulutusohjelmia" << endl;
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "Koulutusohjelmien maara: ";
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::tuoTiedot()
{
	string valinta;

	cout << "Tuo opettajia (1), tai opiskelijoita (2): ";
	getline(cin, valinta);

	while (valinta != "1" && valinta != "2")
	{
		cout << "Virheellinen valinta, yrita uudelleen: ";
		getline(cin, valinta);
	}

	// Lukutiedostopointer
	ifstream inFile;

	if (valinta == "1")
	{

		// Yritä avata tiedosto, jos ei onnistu niin tulosta viesti ja palaa
		try
		{
			inFile.open("Opettajat.csv");

			if (!inFile.is_open())
			{
				throw "Tiedostoa ei voitu avata";
			}
		}
		catch (const char* error)
		{
			cout << endl << error << endl;
			return;
		}

		// Jos avaaminen onnistui, lisää opettajat
		string rivi;

		while (inFile.peek() != EOF)
		{
			// Opettajatiedoille apumuuttujat
			string kOhjelma, etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
			// Lue yksi rivi (1 opettaja)
			getline(inFile, rivi);
			// Tee rivista luettava stream nimelta tieto
			istringstream tieto(rivi);

			// Lue rivilta tiedot
			getline(tieto, kOhjelma, ';');
			getline(tieto, etunimi, ';');
			getline(tieto, sukunimi, ';');
			getline(tieto, osoite, ';');
			getline(tieto, puhelinnumero, ';');
			getline(tieto, tunnus, ';');
			getline(tieto, palkka, ';');
			getline(tieto, opetusala, ';');

			// Tarkasta onko koulutusohjelmia olemassa yhtakaan
			if (koulutusohjelmat_.size() > 0)
			{
				bool onOlemassa = false;  // Apumuuttuja

				// Tarkasta onko lisattava koulutusohjelma jo vektorissa
				for (int i = 0; i != koulutusohjelmat_.size(); i++)
				{
					if (koulutusohjelmat_[i].annaNimi() == kOhjelma)
					{
						// Loytyi olemassa oleva ohjelma, lisataan siihen opettaja
						onOlemassa = true;
						koulutusohjelmat_[i].tuoOpettaja(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala);
						cout << "Opettaja lisatty!" << endl;
					}
				}

				// Jos koulutusohjelmaa ei loydy vektorista, luodaan uusi koulutusohjelma
				if (!onOlemassa)
				{
					koulutusohjelmat_.push_back(Koulutusohjelma(kOhjelma));

					// Etsitaan tehty koulutusohjelma ja lisataan opettaja
					for (int j = 0; j != koulutusohjelmat_.size(); j++)
					{
						if (koulutusohjelmat_[j].annaNimi() == kOhjelma)
						{
							koulutusohjelmat_[j].tuoOpettaja(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala);
						}
					}
				}
			}
			// Koulutusohjelmia ei viela olemassa
			else
			{
				// Luodaan uusi
				koulutusohjelmat_.push_back(Koulutusohjelma(kOhjelma));

				// Etsitaan tehty koulutusohjelma ja lisataan opettaja
				for (int j = 0; j != koulutusohjelmat_.size(); j++)
				{
					if (koulutusohjelmat_[j].annaNimi() == kOhjelma)
					{
						koulutusohjelmat_[j].tuoOpettaja(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala);
						cout << "Opettaja lisatty!" << endl;
					}
				}
			}
		}
		
		
	}
	else
	{
		// Yritä avata tiedosto, jos ei onnistu niin tulosta viesti ja palaa
		try
		{
			inFile.open("Opiskelijat.csv");

			if (!inFile.is_open())
			{
				throw "Tiedostoa ei voitu avata";
			}
		}
		catch (const char* error)
		{
			cout << endl << error << endl;
			return;
		}

		// Jos avaaminen onnistui, lisää opiskelijat
		string rivi;

		while (inFile.peek() != EOF)
		{
			// Opiskelijatiedoille apumuuttujat
			string kOhjelma, etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;

			// Lue 1 rivi (1 opiskelija)
			getline(inFile, rivi);

			// Tee rivista luettava stream nimelta tieto
			istringstream tieto(rivi);

			// Lue rivilta tiedot
			getline(tieto, kOhjelma, ';');
			getline(tieto, etunimi, ';');
			getline(tieto, sukunimi, ';');
			getline(tieto, osoite, ';');
			getline(tieto, puhelinnumero, ';');
			getline(tieto, opiskelijanumero, ';');

			// Tarkasta onko koulutusohjelmia olemassa yhtakaan
			if (koulutusohjelmat_.size() > 0)
			{
				bool onOlemassa = false;  // Apumuuttuja

				// Tarkasta onko lisattava koulutusohjelma jo vektorissa
				for (int i = 0; i != koulutusohjelmat_.size(); i++)
				{
					if (koulutusohjelmat_[i].annaNimi() == kOhjelma)
					{
						// Loytyi olemassa oleva ohjelma, lisataan siihen opiskelija
						onOlemassa = true;
						koulutusohjelmat_[i].tuoOpiskelija(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
						cout << "Opiskelija lisatty!" << endl;
					}
				}

				// Jos koulutusohjelmaa ei loydy vektorista, luodaan uusi koulutusohjelma
				if (!onOlemassa)
				{
					koulutusohjelmat_.push_back(Koulutusohjelma(kOhjelma));

					// Etsitaan tehty koulutusohjelma ja lisataan opiskelija
					for (int j = 0; j != koulutusohjelmat_.size(); j++)
					{
						if (koulutusohjelmat_[j].annaNimi() == kOhjelma)
						{
							koulutusohjelmat_[j].tuoOpiskelija(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
						}
					}
				}
			}
			// Koulutusohjelmia ei viela olemassa
			else
			{
				// Luodaan uusi
				koulutusohjelmat_.push_back(Koulutusohjelma(kOhjelma));

				// Etsitaan tehty koulutusohjelma ja lisataan opiskelija
				for (int j = 0; j != koulutusohjelmat_.size(); j++)
				{
					if (koulutusohjelmat_[j].annaNimi() == kOhjelma)
					{
						koulutusohjelmat_[j].tuoOpiskelija(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
						cout << "Opiskelija lisatty!" << endl;
					}
				}
			}

		}
	}
	inFile.close();
}

void Koulu::vieTiedot()
{
	string valinta;

	if (koulutusohjelmat_.size() == 0)
	{
		cout << "Ei vietavia tietoja" << endl;
		return;
	}

	cout << "Vie opettajia (1), tai opiskelijoita (2): ";
	getline(cin, valinta);

	while (valinta != "1" && valinta != "2")
	{
		cout << "Virheellinen valinta, yrita uudelleen: ";
		getline(cin, valinta);
	}

	// Kirjoituspointer
	ofstream outFile;

	if (valinta == "1")
	{
		outFile.open("Opettajat.csv");

		for (int i = 0; i < koulutusohjelmat_.size(); i++)
		{
			// Hae koulutusohjelman opettajat vektoriin
			vector<Opettaja> opettajat = koulutusohjelmat_[i].annaOpettajat();

			if (opettajat.size() > 0)
			{
				for (int j = 0; j < opettajat.size(); j++)
				{
					outFile << koulutusohjelmat_[i].annaNimi() << ";";
					outFile << opettajat[j].annaEtunimi() << ";";
					outFile << opettajat[j].annaSukunimi() << ";";
					outFile << opettajat[j].annaOsoite() << ";";
					outFile << opettajat[j].annaPuhelinnumero() << ";";
					outFile << opettajat[j].annaTunnus() << ";";
					outFile << opettajat[j].annaPalkka() << ";";
					outFile << opettajat[j].annaOpetusala();
					outFile << endl;
				}
				cout << endl << "Opettajat tallennettu!" << endl;
			}
		}
	}

	else
	{
		outFile.open("Opiskelijat.csv");

		for (int i = 0; i < koulutusohjelmat_.size(); i++)
		{
			// Hae koulutusohjelman opiskelijat vektoriin
			vector<Opiskelija> opiskelijat = koulutusohjelmat_[i].annaOpiskelijat();

			if (opiskelijat.size() > 0)
			{
				for (int j = 0; j < opiskelijat.size(); j++)
				{
					outFile << koulutusohjelmat_[i].annaNimi() << ";";
					outFile << opiskelijat[j].annaEtunimi() << ";";
					outFile << opiskelijat[j].annaSukunimi() << ";";
					outFile << opiskelijat[j].annaOsoite() << ";";
					outFile << opiskelijat[j].annaPuhelinnumero() << ";";
					outFile << opiskelijat[j].annaOpiskelijanumero();
					outFile << endl;
				}
				cout << endl << "Opiskelijat tallennettu!" << endl;
			}
		}
	}
	outFile.close();
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	// Etsi koulutusohjelma-funktio
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].lisaaOpettaja();
	}
}

void Koulu::tulostaKoulutusohjelmanOpettajat()
{
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].tulostaOpettajat();
	}
}

void Koulu::poistaKoulutusohjelmanOpettaja()
{
	string tunnus;
	
	int etsi = etsiKoulutusohjelma();

	// Jos koulutusohjelma loytyi kutsu poistaOpettajaa
	if (etsi != -1)
	{
		cout << "Anna opettajan tunnus: ";
		getline(cin, tunnus);
		koulutusohjelmat_[etsi].poistaOpettaja(tunnus);
	}
}

void Koulu::paivitaOpettajanTiedot()
{
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].paivitaOpettaja();
	}
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].lisaaOpiskelija();
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat()
{
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].tulostaOpiskelijat();
	}
}

void Koulu::poistaKoulutusohjelmanOpiskelija()
{
	string numero; // Apumuuttuja

	int etsi = etsiKoulutusohjelma();

	// Jos koulutusohjelma loytyi
	if (etsi != -1)
	{
		cout << "Anna opiskelijanumero: ";
		getline(cin, numero);
		koulutusohjelmat_[etsi].poistaOpiskelija(numero);
	}
}

void Koulu::paivitaOpiskelijanTiedot()
{
	int etsi = etsiKoulutusohjelma();

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].paivitaOpiskelija();
	}
}
