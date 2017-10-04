#pragma once
class Kello
{
public:
	Kello(); // oletusrak.
	Kello(int hh, int mm, int ss); // param. rak.
	Kello(const Kello &alkup); // kopiorakentaja
	~Kello();

	//getters
	int annaTunnit() const;
	int annaMinuutit() const;
	int annaSekunnit() const;

	// setters
	void asetaTunnit(int hh);
	void asetaMinuutit(int mm);
	void asetaSekunnit(int ss);

	void asetaAika(int hh, int mm, int ss);
	void tulosta() const;
	void lisaaSekunti();
private:
	int hh_;
	int mm_;
	int ss_;
};