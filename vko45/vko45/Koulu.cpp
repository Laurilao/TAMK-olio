#include "Koulu.h"
#include <iostream>

using std::endl; using std::cout; using std::cin; using std::getline;

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

int Koulu::etsiKoulutusohjelma(string nimi)
{
	for (int i = 0; i != koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_[i].annaNimi())
		{
			return i;
		}
	}
	return -1;
}

void Koulu::lisaaKoulutusohjelma()
{
	string ohjelma; // Apumuuttuja

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, ohjelma);
	
	koulutusohjelmat_.push_back(Koulutusohjelma(ohjelma));
}

void Koulu::tulostaKoulutusohjelmat()
{
	for (int i = 0; i != koulutusohjelmat_.size(); i++)
	{
		cout << "Koulutusohjelmat: " << endl;
		cout << koulutusohjelmat_[i].annaNimi() << endl;
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "Koulutusohjelmien maara: ";
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	string nimi;	// Apumuuttujat
	int etsi;

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);

	etsi = etsiKoulutusohjelma(nimi);

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].lisaaOpettaja();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt" << endl;

}

void Koulu::tulostaKoulutusohjelmanOpettajat()
{
	string nimi;	// Apumuuttujat
	int etsi;

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);

	etsi = etsiKoulutusohjelma(nimi);

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].tulostaOpettajat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt" << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	string nimi;	// Apumuuttujat
	int etsi;

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);

	etsi = etsiKoulutusohjelma(nimi);

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].lisaaOpiskelija();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt" << endl;

}

void Koulu::tulostaKoulutusohjelmanOpiskelijat()
{
	string nimi;	// Apumuuttujat
	int etsi;

	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);

	etsi = etsiKoulutusohjelma(nimi);

	if (etsi != -1)
	{
		koulutusohjelmat_[etsi].tulostaOpiskelijat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt" << endl;
}