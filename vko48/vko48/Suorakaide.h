#pragma once
#include "Kuvio.h"
class Suorakaide :
	public Kuvio
{
public:
	Suorakaide();
	Suorakaide(double leveys, double korkeus);
	~Suorakaide();

	double pintaAla() const;

private:
	double leveys_;
	double korkeus_;
};

