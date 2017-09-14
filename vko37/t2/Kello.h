#pragma once

class Kello
{
public:
	Kello();
	Kello(int hh, int mm, int ss);
	~Kello();

	// getters
	int annaTunnit();
	int annaMinuutit();
	int annaSekunnit();

	// setters
	void asetaTunnit(int hh);
	void asetaMinuutit(int mm);
	void asetaSekunnit(int ss);

	void tulosta();
	void asetaAika(int hh, int mm, int ss);
	void lisaaSekunti();

private:
	int ss_;
	int mm_;
	int hh_;

};

