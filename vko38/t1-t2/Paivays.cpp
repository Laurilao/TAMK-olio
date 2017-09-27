#include <iostream>

#include "Paivays.h"

using std::cout; using std::endl;

Paivays::Paivays() : pp_(1), kk_(1), vv_(1970)
{
	cout << "Paivays: oletusrak. " << this << endl;
}

Paivays::Paivays(int pp, int kk, int vv) : pp_(pp), kk_(kk), vv_(vv)
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

void Paivays::lisaaPaiva()
{
	pp_++;

	// Kuukaudet heinäkuuhun asti
	if (kk_ <= 7)
	{
		// Jos helmikuu
		if (kk_ == 2)
		{
			// Onko karkausvuosi?
			if (vv_ % 4 == 0)
			{
				if (pp_ > 29)
				{
					pp_ = 1;
					kk_++;
				}
			}
			else
			{
				if (pp_ > 28)
				{
					pp_ = 1;
					kk_++;
				}
			}
		}
		// Jos parillinen kuukausi ja ei helmikuu
		else if (kk_ % 2 == 0 && kk_ != 2)
		{
			if (pp_ > 30)
			{
				pp_ = 1;
				kk_++;
			}
		}
		// Jos pariton kuukausi
		else if (kk_ % 2 != 0)
		{
			if (pp_ > 31)
			{
				pp_ = 1;
				kk_++;
			}
		}
	}

	// Kuukaudet elokuusta eteenpäin
	else if (kk_ > 7)
	{
		// Jos parillinen kuukausi
		if (kk_ % 2 == 0)
		{
			if (pp_ > 31)
			{
				pp_ = 1;
				kk_++;
			}
		}
		// Jos pariton kuukausi
		else if (kk_ % 2 != 0)
		{
			if (pp_ > 30)
			{
				pp_ = 1;
				kk_++;
			}
		}
	}
	// Tarkista vaihtuuko vuosi
	if (kk_ > 12)
	{
		pp_ = 1;
		kk_ = 1;
		vv_++;
	}

}

void Paivays::montakoPaivaaKuukaudessa()
{
	// Kuukaudet heinäkuuhun asti
	if (kk_ <= 7)
	{
		// Jos helmikuu
		if (kk_ == 2)
		{
			// Tarkista karkausvuosi
			if (vv_ % 4 == 0)
			{
				cout << "Kuukaudessa on 29 paivaa" << endl;
				return;
			}
			else
			{
				cout << "Kuukaudessa on 28 paivaa" << endl;
				return;
			}
			
		}
		// Jos parillinen ja ei helmikuu
		else if (kk_ % 2 == 0 && kk_ != 2)
		{
			cout << "Kuukaudessa on 30 paivaa" << endl;
			return;
		}
		// Jos pariton
		else if (kk_ % 2 != 0)
		{
			cout << "Kuukaudessa on 31 paivaa" << endl;
			return;
		}
	}
	// Kuukauden elokuusta eteenpäin
	else if (kk_ > 7)
	{
		// Jos parillinen
		if (kk_ % 2 == 0)
		{
			cout << "Kuukaudessa on 31 paivaa" << endl;
			return;
		}
		// Jos pariton
		else if (kk_ % 2 != 0)
		{
			cout << "Kuukaudessa on 30 paivaa" << endl;
			return;
		}
	}

}
