#include <iostream>

void printTahdet(int maara);

int main()
{
	// Opiskelijoiden lukumr, keskiarvo, ja arvosanojen kokonaismr
	double op_lkm = 0, keskiarvo = 0, kokonaismaara = 0;
	// Arvosanojen kokonaistulos KA:n laskemista varten
	int arvosanat[6] = { 0,0,0,0,0,0 };
	int syotenro;

	do
	{
		std::cout << "Anna arvosana: ";
		std::cin >> syotenro;
		std::cout << std::endl;
		if (syotenro >= 0 && syotenro <= 5)
		{
			arvosanat[syotenro]++;
			op_lkm++;
			kokonaismaara += syotenro;
		}
		else if (syotenro > 5)
		{
			std::cout << "Numero oltava vlill 0-5" << std::endl << std::endl;
		}

	} while (syotenro >= 0);


	std::cout << "Arvosana Lkm Histogrammi" << std::endl;
	std::cout << "0 " << arvosanat[0] << " ";
	printTahdet(arvosanat[0]);
	std::cout << std::endl;
	std::cout << "1 " << arvosanat[1] << " ";
	printTahdet(arvosanat[1]);
	std::cout << std::endl;
	std::cout << "2 " << arvosanat[2] << " ";
	printTahdet(arvosanat[2]);
	std::cout << std::endl;
	std::cout << "3 " << arvosanat[3] << " ";
	printTahdet(arvosanat[3]);
	std::cout << std::endl;
	std::cout << "4 " << arvosanat[4] << " ";
	printTahdet(arvosanat[4]);
	std::cout << std::endl;
	std::cout << "5 " << arvosanat[5] << " ";
	printTahdet(arvosanat[5]);
	std::cout << std::endl;

	keskiarvo = kokonaismaara / op_lkm;

	std::cout << "Opiskelijoita: " << op_lkm << " Keskiarvo: " << keskiarvo << std::endl;

	return 0;

}

void printTahdet(int maara)
{
	for (int i = 0; i < maara; i++)
	{
		std::cout << "*";
	}
}