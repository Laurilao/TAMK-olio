#include <iostream>
#include <cmath>
#include "Suorakaide.h"
#include "Ympyra.h"

using std::cout; using std::cin; using std::endl;

int main()
{
	Ympyra ymp = Ympyra(5.0);
	Suorakaide sk = Suorakaide(4.0, 6.0);
	Kuvio* y_ptr = &ymp;
	Kuvio* sk_ptr = &sk;

	cout << "Ympyra pinta-ala: " << y_ptr->pintaAla() << endl;
	cout << "Suorakaiteen pinta-ala: " << sk_ptr->pintaAla() << endl;

	y_ptr = 0;
	sk_ptr = 0;

	system("pause");
	return 0;
}