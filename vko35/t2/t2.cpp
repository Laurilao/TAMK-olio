#include <iostream>

int main()
{
	double kulutus[6] = { 7.8, 8.1, 8.05, 7.7, 7.9, 8.21 };

	std::cout << "Normikulutuslukemat (l/100km) ovat:" << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 << ". Lukema: " << kulutus[i] << std::endl;
	}

	return 0;
}