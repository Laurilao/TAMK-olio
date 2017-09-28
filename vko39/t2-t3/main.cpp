#include <iostream>

#include "Kello.h"

int main()
{
	/* T2

	Kello omega;
	Kello rolex(9, 25, 43);
	Kello rantaRolex(rolex);

	omega.tulosta();
	rolex.tulosta();
	rantaRolex.tulosta();*/

	// T3

	Kello* k1_ptr = new Kello;
	Kello* k2_ptr = new Kello(12, 33, 12);
	Kello* k3_ptr = new Kello(*k2_ptr);

	if (k1_ptr)
	{
		k1_ptr->tulosta();
		delete k1_ptr;
		k1_ptr = 0;
	}

	if (k2_ptr)
	{
		k2_ptr->tulosta();
		delete k2_ptr;
		k2_ptr = 0;
	}

	if (k3_ptr)
	{
		k3_ptr->tulosta();
		delete k3_ptr;
		k3_ptr = 0;
	}

	system("pause");
	return 0;
}