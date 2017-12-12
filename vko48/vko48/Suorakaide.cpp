#include "Suorakaide.h"



Suorakaide::Suorakaide()
{
}

Suorakaide::Suorakaide(double leveys, double korkeus) : leveys_(leveys), korkeus_(korkeus)
{
}


Suorakaide::~Suorakaide()
{
}

double Suorakaide::pintaAla() const
{
	return (leveys_ * korkeus_);
}
