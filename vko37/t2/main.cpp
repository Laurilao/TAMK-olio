#include <iostream>
#include <Windows.h>

#include "Kello.h"

using std::cout; using std::endl; using std::cin;

int main()
{
	Kello omega;
	Kello rolex(23, 58, 57);

	omega.tulosta();
	rolex.tulosta();


	system("pause");
	return 0;
}
