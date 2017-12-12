#pragma once
#include "Kuvio.h"
#include <cmath>

class Ympyra :
	public Kuvio
{
public:
	Ympyra();
	Ympyra(double halkaisija);
	~Ympyra();

	double pintaAla() const;

private:
	double halkaisija_;
};

