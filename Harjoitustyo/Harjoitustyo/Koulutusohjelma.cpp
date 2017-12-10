#include <iostream>
#include <fstream>
#include "Koulutusohjelma.h"

using std::endl; using std::cout; using std::cin; using std::getline; using std::ifstream; using std::ofstream;

Koulutusohjelma::Koulutusohjelma() : Opettaja(), Opiskelija(), nimi_("Ei ohjelmaa")
{
	//cout << "Oletusrakentaja (koulutusohjelma)" << endl;
}

Koulutusohjelma::Koulutusohjelma(string nimi) : Opettaja(), Opiskelija(), nimi_(nimi)
{
	//cout << "Param. rakentaja (koulutusohjelma)" << endl;
}

Koulutusohjelma & Koulutusohjelma::operator=(const Koulutusohjelma & alkup)
{
	Opettaja::operator=(alkup);
	Opiskelija::operator=(alkup);

	if (this != &alkup)
	{
		nimi_ = alkup.nimi_;

		for (int i = 0; i != opiskelijat_.size(); i++)
		{
			opiskelijat_[i] = alkup.opiskelijat_[i];
		}
		for (int i = 0; i != opettajat_.size(); i++)
		{
			opettajat_[i] = alkup.opettajat_[i];
		}
	}

	return *this;
}


Koulutusohjelma::~Koulutusohjelma()
{
	//cout << "Koulutusohjelmapurkaja" << endl;
}

string Koulutusohjelma::annaNimi()
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

void Koulutusohjelma::lisaaOpettaja()
{
	// Uusi opettajaolio
	Opettaja uusiope = Opettaja();
	uusiope.kysyTiedot();

	// Lisaa olio vektoriin
	opettajat_.push_back(uusiope);
	cout << "Opettaja lisatty!" << endl;
}

void Koulutusohjelma::poistaOpettaja(string tunnus)
{
	int valinta;  // Apumuuttuja

	// Etsi opettajaa vektorista
	for (int i = 0; i != opettajat_.size(); i++)
	{
		if (opettajat_[i].annaTunnus() == tunnus)
		{	
			// Jos tunnus loytyy, tarkista
			// onko samalla tunnuksella useita opettajia
			if (samaTunnus(tunnus) == false)
			{
				// Jos uniikki tunnus, poista opettaja
				opettajat_.erase(opettajat_.begin() + i);
				cout << "Opettaja poistettu!" << endl;
				return;
			}
			else
			{
				// Jos samoja tunnuksia loytyy, pyyda kayttajaa valitsemaan opettaja listalta
				cout << endl << "Valitse poistettava opettaja (1-" << opettajat_.size() << "): ";
				valinta = Koulutusohjelma::valitseOpettaja();
				opettajat_.erase(opettajat_.begin() + valinta);
				cout << "Opettaja poistettu!" << endl;
				return;
			}
		}
	}
	cout << "Opettajaa ei loytynyt" << endl;
}

void Koulutusohjelma::lisaaOpiskelija()
{
	// Uusi opiskelijaolio
	Opiskelija uusiopiskelija = Opiskelija();
	uusiopiskelija.kysyTiedot();

	// Lisaa olio vektoriin
	opiskelijat_.push_back(uusiopiskelija);
	cout << "Opiskelija lisatty!" << endl;
}

void Koulutusohjelma::poistaOpiskelija(string numero)
{
	int valinta; // Apumuuttuja

	// Etsi opiskelija vektorista
	for (int i = 0; i != opiskelijat_.size(); i++)
	{
		if (opiskelijat_[i].annaOpiskelijanumero() == numero)
		{	
			// Jos opiskelijanumero loytyy, tarkista
			// onko samalla numerolla useita opiskelijoita
			if (samaNumero(numero) == false)
			{
				// Jos uniikki numero, paivita tiedot
				opiskelijat_.erase(opiskelijat_.begin() + i);
				cout << "Opiskelija poistettu!" << endl;
				return;
			}
			else
			{
				// Jos samoja numeroita loytyy, pyyda kayttajaa valitsemaan opiskelija listalta
				cout << endl << "Valitse poistettava opiskelija (1-" << opiskelijat_.size() << "): ";
				valinta = Koulutusohjelma::valitseOpiskelija();
				opiskelijat_.erase(opiskelijat_.begin() + valinta);
				cout << "Opiskelija poistettu!" << endl;
				return;
			}
		}
	}
	cout << "Opiskelijaa ei loytynyt" << endl;
}

void Koulutusohjelma::tulostaOpettajat()
{
	cout << "--------------" << endl;
	cout << "Opettajia: " << opettajat_.size() << endl;
	cout << "--------------" << endl;

	for (int i = 0; i != opettajat_.size(); i++)
	{
		opettajat_[i].tulosta();

		if (i != (opettajat_.size() - 1))
		{
			cout << "----" << endl;
		}
	}
}

void Koulutusohjelma::paivitaOpettaja()
{
	string tunnus;  // Apumuuttujat
	int valinta;    // 

	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus);

	for (int i = 0; i != opettajat_.size(); i++)
	{
		if (opettajat_[i].annaTunnus() == tunnus)
		{
			// Tarkista onko samalla tunnuksella useita opettajia
			if (samaTunnus(tunnus) == false)
			{
				// Jos uniikki tunnus, paivita tiedot
				opettajat_[i].kysyTiedot();
				cout << "Tiedot paivitetty!" << endl;
				return;
			}
			else
			{
				// Jos samoja tunnuksia loytyy, pyyda kayttajaa valitsemaan opettaja listasta
				cout << endl << "Valitse paivitettava opettaja (1-" << opettajat_.size() << "): ";
				valinta = Koulutusohjelma::valitseOpettaja();
				opettajat_[valinta].kysyTiedot();
				cout << "Tiedot paivitetty!" << endl;
				return;
			}
		}
	}
	cout << "Opettajaa ei loydy talla tunnuksella" << endl;
}

bool Koulutusohjelma::samaTunnus(string tunnus)
{
	// Tama funktio kay opettajavektorin lapi ja tarkastaa onko
	// useita opettajia tallennettu samalla tunnuksella
	// ja tulostaa opettajalistan jos samoja loytyy

	int samoja = 0;

	// Jos opettajia alle 2, palauta 0 automaattisesti
	if (opettajat_.size() < 2)
	{
		return false;
	}
	// Jos opettajia yli 2, tarkasta onko samoja tunnuksia
	else
	{
		for (int x = 0; x != opettajat_.size(); x++)
		{
			if (opettajat_[x].annaTunnus() == tunnus)
			{
				samoja++;
			}
		}
		// Jos samoja tunnuksia loytyy enemman kuin 1, tulostaa opettajalistan
		if (samoja > 1)
		{
			cout << endl << "Samalla tunnuksella loytyi " << samoja << " opettajaa!" << endl;
			tulostaOpettajat();
			return true;
		}
	}
	return false;
}

void Koulutusohjelma::tulostaOpiskelijat()
{
	cout << "--------------" << endl;
	cout << "Opiskelijoita: " << opiskelijat_.size() << endl;
	cout << "--------------" << endl;

	for (int i = 0; i != opiskelijat_.size(); i++)
	{
		opiskelijat_[i].tulosta();

		if (i != (opiskelijat_.size() - 1))
		{
			cout << "----" << endl;
		}
	}
}

void Koulutusohjelma::paivitaOpiskelija()
{
	string numero;  // Apumuuttujat
	int valinta;    // 

	cout << "Anna opiskelijanumero: ";
	getline(cin, numero);

	for (int i = 0; i != opiskelijat_.size(); i++)
	{
		if (opiskelijat_[i].annaOpiskelijanumero() == numero)
		{
			// Tarkista onko samalla numerolla useita opiskelijoita
			if (samaNumero(numero) == false)
			{
				// Jos uniikki numero, paivita tiedot
				opiskelijat_[i].kysyTiedot();
				cout << "Tiedot paivitetty!" << endl;
				return;
			}
			else
			{
				// Jos samoja numeroita loytyy, pyyda kayttajaa valitsemaan opiskelija listalta
				cout << endl << "Valitse paivitettava opiskelija (1-" << opiskelijat_.size() << "): ";
				valinta = Koulutusohjelma::valitseOpiskelija();
				opiskelijat_[valinta].kysyTiedot();
				cout << "Tiedot paivitetty!" << endl;
				return;
			}
		}
	}
	cout << "Opiskelijaa ei loydy talla tunnuksella" << endl;
}

bool Koulutusohjelma::samaNumero(string numero)
{
	/* Tama funktio kay opiskelijavektorin lapi ja tarkastaa onko
	   useita opiskelijoita tallennettu samalla opiskelijanumerolla
	   ja tulostaa opiskelijalistan jos samoja loytyy */

	int samoja = 0; 

	// Jos opiskelijoita alle 2, palauta 0 automaattisesti
	if (opiskelijat_.size() < 2)
	{
		return false;
	}
	// Jos opiskelijoita yli 2, tarkasta onko samoja opiskelijanumeroita
	else
	{
		for (int x = 0; x != opiskelijat_.size(); x++)
		{
			if (opiskelijat_[x].annaOpiskelijanumero() == numero)
			{
				samoja++;
			}
		}
		// Jos samoja tunnuksia loytyy enemman kuin 1, tulostaa opiskelijalistan
		if (samoja > 1)
		{
			cout << endl << "Samalla numerolla loytyi " << samoja << " opiskelijaa!" << endl;
			tulostaOpiskelijat();
			return true;
		}
	}
	return false;
}

int Koulutusohjelma::valitseOpiskelija()
{
	/* Jos samalla numerolla olevia opiskelijoita loytyy, tama funktio pyytaa kayttajaa 
	   valitsemaan tulostetusta listasta opiskelijan, suorittaa 
	   syotteentarkastelun ja palauttaa valitun opiskelijan vektori-indeksin */

	string valinta;
	int numero;

	getline(cin, valinta);

	// Jos valinta ei ole muunnettavissa kokonaisluvuksi tai on suurempi kuin opiskelijavektorin koko
	while (!(atoi(valinta.c_str())) || atoi(valinta.c_str()) > opiskelijat_.size())
	{
		cout << "Virheellinen valinta, yrita uudelleen: ";
		getline(cin, valinta);
	}

	// Muunnetaan valinta kokonaisluvuksi
	numero = atoi(valinta.c_str());

	// Vektori 0-indeksoitu, palautetaan siis (valinta - 1)
	return numero - 1;
}

void Koulutusohjelma::tuoOpiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero)
{
	// Luodaan uusi opiskelija
	Opiskelija uusi = Opiskelija();
	uusi.asetaEtunimi(etunimi);
	uusi.asetaSukunimi(sukunimi);
	uusi.asetaOsoite(osoite);
	uusi.asetaPuhelinnumero(puhelinnumero);
	uusi.asetaOpiskelijanumero(opiskelijanumero);

	// Lisataan opiskelija vektoriin
	opiskelijat_.push_back(uusi);
}

vector<Opiskelija> Koulutusohjelma::annaOpiskelijat()
{
	if (opiskelijat_.size() > 0)
	{
		vector<Opiskelija> oppilaat;

		for (int i = 0; i < opiskelijat_.size(); i++)
		{
			oppilaat.push_back(opiskelijat_[i]);
		}

		return oppilaat;
	}
}



void Koulutusohjelma::tulosta()
{
	cout << "Koulutusohjelma: " << nimi_ << endl;
}

int Koulutusohjelma::valitseOpettaja()
{
	/* Jos samalla tunnuksella olevia opettajia loytyy, tama funktio pyytaa kayttajaa
	   valitsemaan tulostetusta listasta opettajan, suorittaa
	   syotteentarkastelun ja palauttaa valitun opettajan vektori-indeksin */

	string valinta;
	int numero;
	
	getline(cin, valinta);

	// Jos valinta ei ole muunnettavissa kokonaisluvuksi tai on suurempi kuin opettajavektorin koko
	while (!(atoi(valinta.c_str())) || atoi(valinta.c_str()) > opettajat_.size())
	{
		cout << "Virheellinen valinta, yrita uudelleen: ";
		getline(cin, valinta);
	}

	// Muunnetaan valinta kokonaisluvuksi
	numero = atoi(valinta.c_str());

	// Vektori 0-indeksoitu, palautetaan siis valinta - 1
	return numero - 1;
}

void Koulutusohjelma::tuoOpettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, string palkka, string tunnus, string opetusala)
{
	// Muunnetaan palkka doubleksi
	double palkkaStr = atof(palkka.c_str());

	Opettaja uusi = Opettaja();
	uusi.asetaEtunimi(etunimi);
	uusi.asetaSukunimi(sukunimi);
	uusi.asetaOsoite(osoite);
	uusi.asetaPuhelinnumero(puhelinnumero);
	uusi.asetaPalkka(palkkaStr);
	uusi.asetaTunnus(tunnus);
	uusi.asetaOpetusala(opetusala);

	opettajat_.push_back(uusi);
}

vector<Opettaja> Koulutusohjelma::annaOpettajat()
{
	if (opettajat_.size() > 0)
	{
		vector<Opettaja> opet;

		for (int i = 0; i < opettajat_.size(); i++)
		{
			opet.push_back(opettajat_[i]);
		}
		return opet;
	}
}

