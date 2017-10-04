#include <iostream>

#include "Kello.h"

using std::cout; using std::endl;

Kello::Kello() : hh_(0), mm_(0), ss_(0)
{
	cout << "Kello oletusrak" << endl;
}

Kello::Kello(int hh, int mm, int ss) : hh_(hh), mm_(mm), ss_(ss)
{
	cout << "Kello param. rak." << endl;
}

Kello::Kello(const Kello & alkup): hh_(alkup.hh_), mm_(alkup.mm_), ss_(alkup.ss_)
{
	cout << "Kello kopio rak." << endl;
}

Kello::~Kello()
{
	cout << "Kello purkaja" << endl;
}

int Kello::annaTunnit() const
{
	return hh_;
}

int Kello::annaMinuutit() const
{
	return mm_;
}

int Kello::annaSekunnit() const
{
	return ss_;
}

void Kello::asetaTunnit(int hh)
{
	hh_ = hh;
}

void Kello::asetaMinuutit(int mm)
{
	mm_ = mm;
}

void Kello::asetaSekunnit(int ss)
{
	ss_ = ss;
}

void Kello::asetaAika(int hh, int mm, int ss)
{
	hh_ = hh;
	mm_ = mm;
	ss_ = ss;
}

void Kello::tulosta() const
{
	cout << hh_ << ":" << mm_ << ":" << ss_ << endl;
}

void Kello::lisaaSekunti()
{
	ss_++;
	if (ss_ >= 60)
	{
		mm_++;
		ss_ = 0;
		if (mm_ >= 60)
		{
			hh_++;
			mm_ = 0;
			if (hh_ >= 24)
			{
				hh_ = 0;
			}
		}
	}
}