#include <iostream>
#include "Koulutusohjelma.h"

using std::endl; using std::cout; using std::cin; using std::getline;

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
	Opettaja uusiope = Opettaja();
	uusiope.kysyTiedot();
	opettajat_.push_back(uusiope);
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija uusiopiskelija = Opiskelija();
	uusiopiskelija.kysyTiedot();
	opiskelijat_.push_back(uusiopiskelija);
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

void Koulutusohjelma::tulostaOpiskelijat()
{
	cout << "--------------" << endl;
	cout << "Opiskelijoita: " << opettajat_.size() << endl;
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

void Koulutusohjelma::tulosta()
{
	cout << "Koulutusohjelma: " << nimi_ << endl;
}
