#include <iostream>
#include "Koulu.h"


int main()
{
	/* //T1 - T2//

	Koulutusohjelma koulu = Koulutusohjelma();

	koulu.lisaaOpettaja();
	koulu.lisaaOpiskelija();
	koulu.lisaaOpettaja();
	koulu.lisaaOpiskelija();

	koulu.tulostaOpettajat();
	koulu.tulostaOpiskelijat();
	*/

	Koulu school = Koulu();

	school.lisaaKoulutusohjelma();
	school.tulostaKoulutusohjelmat();
	school.tulostaKoulutusohjelmienMaara();

	school.lisaaKoulutusohjelmaanOpettaja();
	school.lisaaKoulutusohjelmaanOpiskelija();

	school.tulostaKoulutusohjelmanOpettajat();
	school.tulostaKoulutusohjelmanOpiskelijat();

	system("pause");
	return 0;
}