#pragma once

class Paivays
{
public:
	Paivays();  // oletusrakentaja
	Paivays(int pp, int kk, int vv);  // param. rakentaja
	~Paivays();  // purkaja

				 // getters (lukurutiinit)
	int annaPaiva();
	int annaKuukausi();
	int annaVuosi();

	// setters (kirjoitusrutiinit)
	void asetaPaiva(int pp);
	void asetaKuukausi(int kk);
	void asetaVuosi(int vv);

	void tulosta();
	void lisaaPaiva();
	void montakoPaivaaKuukaudessa();

private:
	int pp_;
	int kk_;
	int vv_;

};
