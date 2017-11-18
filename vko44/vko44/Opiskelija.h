#pragma once
#include "Henkilo.h"

class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero);
	Opiskelija(const Opiskelija & alkup);
	~Opiskelija();

	string annaOpiskelijanumero() const;
	void asetaOpiskelijanumero(string opiskelijanumero);

	void kysyTiedot();
	void tulosta() const;
private:
	string opiskelijanumero_;
};