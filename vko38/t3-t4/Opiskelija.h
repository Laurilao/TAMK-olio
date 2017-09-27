#include <string>
#pragma once

using std::string;

class Opiskelija
{
public:
	Opiskelija(); // oletusrakentaja
	Opiskelija(int nro, string enimi, string snimi, string email); // param. rakentaja
	~Opiskelija(); // oletuspurkaja

	// getters
	int annaNro();
	string annaEnimi();
	string annaSnimi();
	string annaEmail();

	// setters
	void asetaNro(int nro);
	void asetaEnimi(string enimi);
	void asetaSnimi(string snimi);
	void asetaEmail(string email);

	void tulosta();


private:
	int nro_;
	string enimi_;
	string snimi_;
	string email_;
};

