#include "Opiskelija.h"

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl; using std::cin;

Opiskelija::Opiskelija() : nro_(0), enimi_("Pekka"), snimi_("Pouta"), email_("saa@saa.fi")
{
}

Opiskelija::Opiskelija(int nro, string enimi, string snimi, string email) : nro_(nro), enimi_(enimi), snimi_(snimi), email_(email)
{
}

Opiskelija::~Opiskelija()
{
}

int Opiskelija::annaNro()
{
	return nro_;
}

string Opiskelija::annaEnimi()
{
	return enimi_;
}

string Opiskelija::annaSnimi()
{
	return snimi_;
}

string Opiskelija::annaEmail()
{
	return email_;
}

void Opiskelija::asetaNro(int nro)
{
	nro_ = nro;
}

void Opiskelija::asetaEnimi(string enimi)
{
	enimi_ = enimi;
}

void Opiskelija::asetaSnimi(string snimi)
{
	snimi_ = snimi;
}

void Opiskelija::asetaEmail(string email)
{
	email_ = email;
}

void Opiskelija::tulosta()
{
	cout << "Opiskelija " << nro_ << ": " << enimi_ << " " << snimi_ << ", " << email_ << endl;
}
