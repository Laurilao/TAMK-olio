#include <string>
#pragma once

using std::string;

class Opettaja
{
public:
	Opettaja(); // oletusrakentaja
	Opettaja(int tunnus, string nimi, int palkka); // param. rakentaja
	~Opettaja(); // oletuspurkaja

	// getters
	int annaTunnus();
	string annaNimi();
	int annaPalkka();

	// setters
	void asetaTunnus(int tunnus);
	void asetaNimi(string nimi);
	void asetaPalkka(int palkka);

	void tulosta();


private:
	int tunnus_;
	string nimi_;
	int palkka_;
};

