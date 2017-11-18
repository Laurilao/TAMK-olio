#include <iostream>
#include "Henkilo.h"
#include "Opiskelija.h"
#include "Tyontekija.h"
#include "Opettaja.h"

int main()
{
	// Henkilo-luokan testaus ////////
	Henkilo hlo1 = Henkilo("Olli", "Laurila", "Tekniikankatu", "0401234567");
	hlo1.tulosta();

	Henkilo hlo2 = Henkilo();
	hlo2.kysyTiedot();
	hlo2.tulosta();

	Henkilo hlo3 = Henkilo(hlo1);
	hlo3.tulosta();
	/////////////////////////////////

	std::cout << " /////////////////////////////// " << std::endl;

	// Opiskelija-luokan testaus /////
	Opiskelija op1 = Opiskelija();
	op1.kysyTiedot();
	op1.tulosta();

	Opiskelija op2 = Opiskelija("Olli", "Laurila", "Tekniikankatu", "0401234567", "1302664");
	op2.tulosta();

	Opiskelija op3 = Opiskelija(op2);
	op3.tulosta();
	//////////////////////////////////

	std::cout << " /////////////////////////////// " << std::endl;

	// Tyontekija-luokan testaus /////
	Tyontekija tyo1 = Tyontekija();
	tyo1.kysyTiedot();
	tyo1.tulosta();

	Tyontekija tyo2 = Tyontekija("Olli", "Laurila", "Tekniikankatu", "0401234567", 2500.0, "CODE");
	tyo2.tulosta();

	Tyontekija tyo3 = Tyontekija(tyo2);
	tyo3.tulosta();
	//////////////////////////////////

	std::cout << " /////////////////////////////// " << std::endl;

	// Opettaja-luokan testaus //////
	Opettaja ope1 = Opettaja();
	ope1.kysyTiedot();
	ope1.tulosta();

	Opettaja ope2 = Opettaja("Olli", "Laurila", "Tekniikankatu", "0401234567", 3000.0, "CODE", "Tietotekniikka");
	ope2.tulosta();

	Opettaja ope3 = Opettaja(ope2);
	ope3.tulosta();
	/////////////////////////////////

	system("pause");
	return 0;
}