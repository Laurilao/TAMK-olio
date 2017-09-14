#include <iostream>
#include <iomanip>

#include "Kello.h"

using std::cout; using std::endl; using std::setw; using std::setfill; using std::cin;

Kello::Kello(): hh_(0), mm_(0), ss_(0)
{
}

Kello::Kello(int hh, int mm, int ss): hh_(hh), mm_(mm), ss_(ss)
{
}


Kello::~Kello()
{
}

int Kello::annaTunnit()
{
	return hh_;
}

int Kello::annaMinuutit()
{
	return mm_;
}

int Kello::annaSekunnit()
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

void Kello::tulosta()
{
	cout << hh_ << ":" << mm_ << ":" << ss_ << endl;
}

void Kello::asetaAika(int hh, int mm, int ss)
{
	hh_ = hh;
	mm_ = mm;
	ss_ = ss;
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
