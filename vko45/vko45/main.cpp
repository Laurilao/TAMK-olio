#include <iostream>
#include "Sovellus.h"

int main()
{
	Henkilo hlo1 = Henkilo();
	Henkilo hlo2 = Henkilo("Olli", "Laurila", "teku", "040123456");

	hlo1.tulosta();
	hlo2.tulosta();

	std::cout << "--------------" << std::endl;

	hlo1 = hlo2;

	hlo1.tulosta();
	hlo2.tulosta();

	Tyontekija tyo1 = Tyontekija();
	Tyontekija tyo2 = Tyontekija("Olli", "Laurila", "teku", "041024024", 3000, "OL");

	std::cout << "--------------" << std::endl;

	tyo1.tulosta();
	tyo2.tulosta();

	std::cout << "--------------" << std::endl;

	tyo1 = tyo2;

	tyo1.tulosta();
	tyo2.tulosta();

	std::cout << "--------------" << std::endl;

	Koulutusohjelma ohj1 = Koulutusohjelma("paras");
	Koulutusohjelma ohj2 = Koulutusohjelma("huono");

	ohj1.tulosta();
	ohj2.tulosta();
	
	std::cout << "--------------" << std::endl;

	ohj2 = ohj1;
	ohj1.tulosta();
	ohj2.tulosta();

	ohj1.lisaaOpettaja();
	ohj2.lisaaOpettaja();

	ohj1.tulostaOpettajat();
	ohj2.tulostaOpettajat();

	std::cout << "--------------" << std::endl;

	ohj1 = ohj2;
	ohj1.tulostaOpettajat();
	ohj2.tulostaOpettajat();

	system("pause");
	return 0;
}