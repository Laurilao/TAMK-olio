#pragma once
#include "Tyontekija.h"

class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus, string opetusala);
	Opettaja(const Opettaja & alkup);
	Opettaja& operator=(const Opettaja & alkup);
	~Opettaja();

	string annaOpetusala();

	void asetaOpetusala(string opetusala);

	void kysyTiedot();
	void tulosta();

private:
	string opetusala_;
};

