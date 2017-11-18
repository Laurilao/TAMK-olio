#pragma once
#include "Henkilo.h"

class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus);
	Tyontekija(const Tyontekija & alkup);
	Tyontekija& operator=(const Tyontekija & alkup);
	~Tyontekija();

	double annaPalkka();
	string annaTunnus();

	void asetaPalkka(double palkka);
	void asetaTunnus(string tunnus);

	void kysyTiedot();
	void tulosta();

private:
	double palkka_;
	string tunnus_;
};

