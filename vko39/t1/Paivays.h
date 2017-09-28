#pragma once
class Paivays
{
public:
	Paivays(); // oletusrakentaja
	Paivays(int pp, int kk, int vv); // param. rak. 
	Paivays(const Paivays &alkup); // kopiorakentaja
	~Paivays(); // purkaja
	
	// getters
	int annaPaiva() const;
	int annaKuukausi() const;
	int annaVuosi() const;
	
	// setters
	void asetaPaiva(int pp);
	void asetaKuukausi(int kk);
	void asetaVuosi(int vv);

	void tulosta() const;
	void lisaaPaiva();
	int montakoPaivaaKuukaudessa() const;

private:
	int pp_;
	int kk_;
	int vv_;
};