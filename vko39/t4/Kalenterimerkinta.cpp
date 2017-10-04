#include <iostream>

#include "Kalenterimerkinta.h"

using std::cout; using std::endl; using std::cin;

Kalenterimerkinta::Kalenterimerkinta(): pvm_(), klo_(), asia_(), muistutus_(false)
{
}

Kalenterimerkinta::Kalenterimerkinta(Paivays pvm, Kello klo, string asia, bool muistutus):
	pvm_(pvm), klo_(klo), asia_(asia), muistutus_(muistutus)
{
}

Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta & alkup):
	pvm_(alkup.pvm_), klo_(alkup.klo_), asia_(alkup.asia_), muistutus_(alkup.muistutus_)
{
}


Kalenterimerkinta::~Kalenterimerkinta()
{
}

Paivays Kalenterimerkinta::annaPvm() const
{
	return pvm_;
}

Kello Kalenterimerkinta::annaKlo() const
{
	return klo_;
}

string Kalenterimerkinta::annaAsia() const
{
	return asia_;
}

bool Kalenterimerkinta::annaMuistutus() const
{
	return muistutus_;
}

void Kalenterimerkinta::asetaPvm(Paivays pvm)
{
	pvm_.asetaPaiva(pvm.annaPaiva());  // ei sijoitusoperaattoria paivays-luokassa
	pvm_.asetaKuukausi(pvm.annaKuukausi());
	pvm_.asetaVuosi(pvm.annaVuosi());
}

void Kalenterimerkinta::asetaKlo(Kello klo)
{
	// ei sijoitusoperaattoria kello-luokassa
	klo_.asetaAika(klo.annaTunnit(), klo.annaMinuutit(), klo.annaSekunnit());
}

void Kalenterimerkinta::asetaAsia(string asia)
{
	asia_ = asia;
}

void Kalenterimerkinta::asetaMuistutus(bool muistutus)
{
	muistutus_ = muistutus;
}

void Kalenterimerkinta::tulostaMerkinta() const
{
	cout << "--------------------------------" << endl;
	pvm_.tulosta();
	klo_.tulosta();
	cout << asia_ << endl;
	if (muistutus_)
	{
		cout << "Muistutus paalla" << endl;
	}
	cout << "--------------------------------" << endl;
}

void Kalenterimerkinta::kysyTiedot()
{
	int pp, kk, vv;
	int hh, mm, ss;
	string asia;
	char muistutus;

	cout << "Anna paiva: ";
	cin >> pp;
	cout << "Anna kuukausi: ";
	cin >> kk;
	cout << "Anna vuosi: ";
	cin >> vv;

	pvm_.asetaPaiva(pp);
	pvm_.asetaKuukausi(kk);
	pvm_.asetaVuosi(vv);

	cout << "Anna tunnit: ";
	cin >> hh;
	cout << "Anna minuutit: ";
	cin >> mm;
	cout << "Anna sekunnit: ";
	cin >> ss;

	klo_.asetaAika(hh, mm, ss);

	cout << "Anna asia: ";
	cin.ignore();
	std::getline(cin, asia);

	asia_ = asia;

	cout << "Muistutus paalle? (y/n): ";
	cin >> muistutus;

	if (muistutus == 'y' || muistutus == 'Y')
	{
		muistutus_ = true;
	}
	else
	{
		muistutus_ = false;
	}

}
