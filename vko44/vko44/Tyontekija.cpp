#include "Tyontekija.h"
#include <iostream>

using std::endl; using std::cout; using std::cin; using std::getline;

Tyontekija::Tyontekija() : Henkilo(), palkka_(0.0), tunnus_()
{
	//cout << "Oletusrakentaja (tyontekija)" << endl;
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus) : 
	Henkilo(etunimi, sukunimi, osoite, puhelinnumero), palkka_(palkka), tunnus_(tunnus)
{
	//cout << "Param. rakentaja (tyontekija)" << endl;
}


Tyontekija::Tyontekija(const Tyontekija & alkup) : Henkilo(alkup), palkka_(alkup.palkka_), tunnus_(alkup.tunnus_)
{
	//cout << "Kopiorakentaja (tyontekija)" << endl;
}

Tyontekija::~Tyontekija()
{
	//cout << "Tyontekijapurkaja" << endl;
	//system("pause");
}


double Tyontekija::annaPalkka()
{
	return palkka_;
}


string Tyontekija::annaTunnus()
{
	return tunnus_;
}


void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}


void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}


void Tyontekija::kysyTiedot()
{
	string palkka; //Apumuuttuja

	Henkilo::kysyTiedot();
	cout << "Anna palkka: ";
	getline(cin, palkka);
	cout << "Anna tunnus: ";
	getline(cin, tunnus_);
	palkka_ = atof(palkka.c_str());
}


void Tyontekija::tulosta()
{
	Henkilo::tulosta();
	cout << "Palkka: " << palkka_ << "e, Tunnus: " << tunnus_ << endl;
}
