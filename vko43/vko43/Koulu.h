#pragma once
#include "Koulutusohjelma.h"

class Koulu :
	public Koulutusohjelma
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();

	string annaNimi();
	void asetaNimi(string nimi);

	int etsiKoulutusohjelma(string nimi);

	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelmat();
	void tulostaKoulutusohjelmienMaara() const;

	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat();

	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat();

private:
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
};

