#pragma once
#include <iostream>

class Czas
{
	int godziny;
	int minuty;
	int sekundy;
	void ustawstan_s(int _ile);
	void ustawstan_m(int _ile);
	void ustawstan_h(int _ile);
	int sprawdz(int _h, int _m, int _s, Czas& _to);
	int sprawdz_s(int _ile, Czas& _to);
	int sprawdz_m(int _ile, Czas& _to);
	int sprawdz_h(int _ile, Czas& _to);
public:
	Czas();
	Czas(int _h, int _m, int _s);
	Czas(int _m, int _s);
	Czas(int _s);
	int podajstan_s();
	int podajstan_m();
	int podajstan_h();
	/*int ustawstan(int _h, int _m, int _s, Czas& _to);
	int ustawstan(int _m, int _s, Czas& _to);
	int ustawstan(int _s, Czas& _to);*/
	Czas operator+(Czas _to);
	void wypisz_czas();
	Czas operator+(int liczba);
	bool operator==(Czas _to1);
	bool operator<(Czas _to1);



	
};
