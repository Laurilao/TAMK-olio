#pragma once
#include <vector>
#include <string>
#include "Opettaja.h"
#include "Opiskelija.h"

using std::vector; using std::string;

class Koulutusohjelma :
	public Opettaja,
	public Opiskelija
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	Koulutusohjelma& operator=(const Koulutusohjelma & alkup);
	~Koulutusohjelma();

	// getter & setter
	virtual string annaNimi();
	void asetaNimi(string nimi);

	// Opettajametodit
	void lisaaOpettaja();
	void poistaOpettaja(string tunnus);
	void tulostaOpettajat();
	void paivitaOpettaja();
	bool samaTunnus(string tunnus); // Opettajien tunnusten duplicate tarkastus
	int valitseOpettaja();
	void tuoOpettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, string palkka, string tunnus, string opetusala);
	vector<Opettaja> annaOpettajat();  // Hae koulutusohjelman kaikki opettajat

	// Opiskelijametodit
	void lisaaOpiskelija();
	void poistaOpiskelija(string numero);
	void tulostaOpiskelijat();
	void paivitaOpiskelija();
	bool samaNumero(string numero); // Opiskelijanumeroiden duplicate tarkastus
	int valitseOpiskelija();
	void tuoOpiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero);
	vector<Opiskelija> annaOpiskelijat();  // Hae koulutsohjelman kaikki opiskelijat

	void tulosta();

private:
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

