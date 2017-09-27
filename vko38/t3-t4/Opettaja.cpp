#include "Opettaja.h"

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl; using std::cin;

Opettaja::Opettaja() : tunnus_(0), nimi_("Pekka"), palkka_(3000)
{
}

Opettaja::Opettaja(int tunnus, string nimi, int palkka) : tunnus_(tunnus), nimi_(nimi), palkka_(palkka)
{
}

Opettaja::~Opettaja()
{
}

int Opettaja::annaTunnus()
{
	return tunnus_;
}

string Opettaja::annaNimi()
{
	return nimi_;
}

int Opettaja::annaPalkka()
{
	return palkka_;
}

void Opettaja::asetaTunnus(int tunnus)
{
	tunnus_ = tunnus;
}

void Opettaja::asetaNimi(string nimi)
{
	nimi_ = nimi;
}
void Opettaja::asetaPalkka(int palkka)
{
	palkka_ = palkka;
}

void Opettaja::tulosta()
{
	cout << "Opettaja " << tunnus_ << ": " << nimi_ << ", " << palkka_ << "e" << endl;
}
