#include <iostream>
#include <iomanip>

#include "Kello.h"

using std::cout; using std::endl; using std::setw; using std::setfill; using std::cin;


int Kello::annaTunnit()
{
	do
	{
		cout << "Anna tunnit: ";
		cin >> hh_;
	} while (hh_ < 0 || hh_ > 23);

	return hh_;
}

int Kello::annaMinuutit()
{
	do
	{
		cout << "Anna minuutit: ";
		cin >> mm_;
	} while (mm_ < 0 || mm_ > 59);

	return mm_;
}

int Kello::annaSekunnit()
{
	do
	{
		cout << "Anna sekunnit: ";
		cin >> ss_;
	} while (ss_ < 0 || ss_ > 59);

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
	cout << "\r" << setw(2) << setfill('0') << hh_ << ":"
		<< setw(2) << setfill('0') << mm_ << ":"
		<< setw(2) << setfill('0') << ss_;
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






