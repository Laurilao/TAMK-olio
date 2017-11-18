#include <iostream>
#include "Opiskelija.h"

using std::endl; using std::cout; using std::cin; using std::getline;

Opiskelija::Opiskelija() : Henkilo(), opiskelijanumero_("1301337")
{
	//cout << "Oletusrakentaja (opiskelija)" << endl;
}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero) :
	Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{
	//cout << "Param. rakentaja (opiskelija)" << endl;
}

Opiskelija::Opiskelija(const Opiskelija & alkup) : Henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{
	//cout << "Kopiorakentaja (opiskelija)" << endl;
}

Opiskelija::~Opiskelija()
{
	//cout << "Opiskelijapurkaja" << endl;
	//system("pause");
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	cout << "Opiskelijanumero: " << opiskelijanumero_ << endl;
}
