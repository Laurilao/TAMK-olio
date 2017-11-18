#include <iostream>
#include "Opettaja.h"

using std::endl; using std::cout; using std::cin; using std::getline;

Opettaja::Opettaja() : Tyontekija(), opetusala_("Tyhjanpantti")
{
	cout << "Oletusrakentaja (opettaja)" << endl;
}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus, string opetusala) :
	Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus), opetusala_(opetusala)
{
	cout << "Param. rakentaja (opettaja)" << endl;
}

Opettaja::Opettaja(const Opettaja & alkup) : Tyontekija(alkup), opetusala_(alkup.opetusala_)
{
	cout << "Kopiorakentaja (opettaja)" << endl;
}

Opettaja::~Opettaja()
{
	cout << "Opettajapurkaja" << endl;
	system("pause");
}

string Opettaja::annaOpetusala()
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();
	cout << "Anna opetusala: ";
	getline(cin, opetusala_);
}

void Opettaja::tulosta()
{
	Tyontekija::tulosta();
	cout << "Opetusala: " << opetusala_ << endl;
}
