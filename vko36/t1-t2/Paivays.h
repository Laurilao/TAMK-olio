#pragma once

class Paivays
{
public:
	// getters (lukurutiinit)
	int annaPaiva();
	int annaKuukausi();
	int annaVuosi();

	// setters (kirjoitusrutiinit)
	void asetaPaiva(int pp);
	void asetaKuukausi(int kk);
	void asetaVuosi(int vv);

	void tulosta();

private:
	int pp_;
	int kk_;
	int vv_;

};