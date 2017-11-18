#pragma once
#include "Koulu.h"

class Sovellus :
	public Koulu
{
public:
	Sovellus();
	~Sovellus();

	void aja();

	string tulostaValikko();

private:

};

