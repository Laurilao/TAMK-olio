#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

Paivays::Paivays(): pp_(1), kk_(1), vv_(1970)
{
	cout << "Paivays: oletusrak. " << this << endl;
}

Paivays::Paivays(int pp, int kk, int vv): pp_(pp), kk_(kk), vv_(vv)
{
	cout << "Paivays: param. rak. " << this << endl;
}

Paivays::~Paivays()
{
	cout << "Paivays: purkaja " << this << endl;
	system("pause");

}

int Paivays::annaPaiva()
{
	return pp_;
}

int Paivays::annaKuukausi()
{
	return kk_;
}

int Paivays::annaVuosi()
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

void Paivays::tulosta()
{
	cout << pp_ << "." << kk_ << "." << vv_ << endl;
}
