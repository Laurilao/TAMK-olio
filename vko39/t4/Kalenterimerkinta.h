#pragma once
#include <string>

#include "Kello.h"
#include "Paivays.h"

using std::string;

class Kalenterimerkinta
{
public:
	Kalenterimerkinta();
	Kalenterimerkinta(Paivays pvm, Kello klo, string asia, bool muistutus);
	Kalenterimerkinta(const Kalenterimerkinta &alkup);
	~Kalenterimerkinta();

	// getters
	Paivays annaPvm() const;
	Kello annaKlo() const;
	string annaAsia() const;
	bool annaMuistutus() const;

	// setters
	void asetaPvm(Paivays pvm);
	void asetaKlo(Kello klo);
	void asetaAsia(string asia);
	void asetaMuistutus(bool muistutus);

	void tulostaMerkinta() const;
	void kysyTiedot();

private:
	Paivays pvm_;
	Kello klo_;
	string asia_;
	bool muistutus_;
};

