#include "Ympyra.h"



Ympyra::Ympyra()
{
}

Ympyra::Ympyra(double halkaisija) : halkaisija_(halkaisija)
{
}


Ympyra::~Ympyra()
{
}

double Ympyra::pintaAla() const
{
	double pa, sade;

	sade = halkaisija_ / 2.0;

	pa = (4 * atan(1.0)) * pow(sade, 2.0);
	
	return pa;
}
