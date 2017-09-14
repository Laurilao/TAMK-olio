#pragma once

class Murtoluku
{
public:
	Murtoluku();
	Murtoluku(int os, int nim);
	~Murtoluku();

	// getters
	int annaOsoittaja();
	int annaNimittaja();

	// setters
	void asetaOsoittaja(int os);
	void asetaNimittaja(int nim);

	void kysyTiedot();
	void tulosta();
	void sievenna();
	// etsi suurin yhteinen tekijä
	int syt();

private:
	int os_;
	int nim_;
};

