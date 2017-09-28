#include <iostream>

#include "Paivays.h"

using std::endl; using std::cout;

Paivays::Paivays(): pp_(1), kk_(1), vv_(1970)
{
	cout << "Oletusrakentaja" << endl;
}

Paivays::Paivays(int pp, int kk, int vv): pp_(pp), kk_(kk), vv_(vv)
{
	cout << "Param. rakentaja" << endl;
}

Paivays::Paivays(const Paivays & alkup): pp_(alkup.pp_), kk_(alkup.kk_), vv_(alkup.vv_)
{
	cout << "Kopiorakentaja" << endl;
}


Paivays::~Paivays()
{
}

int Paivays::annaPaiva() const
{
	return pp_;
}

int Paivays::annaKuukausi() const
{
	return kk_;
}

int Paivays::annaVuosi() const
{
	return vv_;
}

void Paivays::asetaPaiva(int pp)
{
	pp_ = pp;
}

void Paivays::asetaKuukausi(int kk)
{
	kk_ = kk;
}

void Paivays::asetaVuosi(int vv)
{
	vv_ = vv;
}

void Paivays::tulosta() const
{
	cout << pp_ << "." << kk_ << "." << vv_ << endl;
}

void Paivays::lisaaPaiva()
{
	int p_lkm = montakoPaivaaKuukaudessa();
	if (pp_ < p_lkm)
		pp_++;
	else
	{
		pp_ = 1;
		kk_++;
		if (kk_ > 12)
		{
			kk_ = 1;
			vv_++;
		}
	}


}

int Paivays::montakoPaivaaKuukaudessa() const
{
	if (kk_ == 1 || kk_ == 3 || kk_ == 5 || kk_ == 7 || kk_ == 8 ||
		kk_ == 10 || kk_ == 12)
		return 31;
	else if (kk_ == 4 || kk_ == 6 || kk_ == 9 || kk_ == 11)
		return 30;
	else if ((vv_ % 4 == 0 && vv_ % 100 != 0) || vv_ % 400 == 0)
		return 29;
	else
		return 28;
	return 0;
}