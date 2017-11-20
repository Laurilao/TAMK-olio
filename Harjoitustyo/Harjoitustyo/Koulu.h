#pragma once
#include "Koulutusohjelma.h"

class Koulu :
	public Koulutusohjelma
{
public:
	// Rakentajat, ylikuormitusoperaattori ja purkaja
	Koulu();
	Koulu(string nimi);
	Koulu& operator=(const Koulu & alkup);
	~Koulu();

	// getter & setter nimelle
	string annaNimi();
	void asetaNimi(string nimi);

	// Apufunktio koulutusohjelmien etsimiseen
	int etsiKoulutusohjelma();

	// Koulutusohjelmien metodit
	void lisaaKoulutusohjelma();
	void poistaKoulutusohjelma();
	void paivitaNimi();
	void tulostaKoulutusohjelmat();
	void tulostaKoulutusohjelmienMaara() const;

	// Tiedostonkasittelymetodit
	void tuoTiedot();
	void vieTiedot();

	// Opettajametodit
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat();
	void poistaKoulutusohjelmanOpettaja();
	void paivitaOpettajanTiedot();

	// Opiskelijametodit
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat();
	void poistaKoulutusohjelmanOpiskelija();
	void paivitaOpiskelijanTiedot();

private:
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
};

