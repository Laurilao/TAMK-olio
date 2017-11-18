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
	~Koulutusohjelma();

	// getter & setter
	string annaNimi();
	void asetaNimi(string nimi);

	void lisaaOpettaja();
	void lisaaOpiskelija();

	void tulostaOpettajat();
	void tulostaOpiskelijat();

	void tulosta();

private:
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

