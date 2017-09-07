#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

int arvoNumerot(int arvotturivi[7]);
void laskeOsumat(int lottorivi[7], int arvotturivi[7], int* osumat);
int pyydaLottorivi(int lottorivi[7]);

int main()
{
	// Koneen arpoma lottorivi
	int arvotturivi[7];
	arvoNumerot(arvotturivi);

	for (int i = 0; i < 7; i++)
	{
		cout << arvotturivi[i] << " ";
	}
	cout << endl << endl;

	// Pyyda kayttajalta lottorivi
	int lottorivi[7];
	pyydaLottorivi(lottorivi);

	// Laske osumat
	int osumat = 0;
	laskeOsumat(lottorivi, arvotturivi, &osumat);

	cout << "Oikeita numeroita: " << osumat << endl;

	system("pause");
	return 0;
}

int arvoNumerot(int arvotturivi[7])
{
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
	{
		arvotturivi[i] = rand() % 39 + 1;

		for (int j = 0; j < i; j++)
		{

			// Tarkista duplicate numerot, uusi tarvittaessa
			while (arvotturivi[i] == arvotturivi[j])
			{
				arvotturivi[i] = rand() % 39 + 1;
			}
		}
	}

	return arvotturivi[7];
}

void laskeOsumat(int lottorivi[7], int arvotturivi[7], int* osumat)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (lottorivi[i] == arvotturivi[j])
			{
				*osumat += 1;
			}
		}
	}
	return;
}

int pyydaLottorivi(int lottorivi[7])
{
	cout << "Syota lottorivi: " << endl;

	for (int i = 0; i < 7; i++)
	{
		cin >> lottorivi[i];

		// Tarkista numeron olevan 1-49
		while (lottorivi[i] > 39 || lottorivi[i] < 1)
		{
			cout << "Numero oltava valilla 1-39" << endl;
			cin >> lottorivi[i];
		}

		// Tarkista duplicate numero
		for (int j = 0; j < i; j++)
		{
			while (lottorivi[i] == lottorivi[j])
			{
				cout << "Numero on jo kaytetty, yrita uudestaan" << endl;
				cin >> lottorivi[i];
			}
		}

	}
	return lottorivi[7];
}
