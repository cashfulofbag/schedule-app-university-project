#pragma once
#include <iostream>
#include "Czas.h"

class Harmonogram
{
	int rozmiar;

public:
	Czas* tab;
	Harmonogram();
	Harmonogram(const Czas _to);
	~Harmonogram();

	Harmonogram(const Harmonogram& _inny, int _ilosc);
	Harmonogram(const Harmonogram& _inny);
	Harmonogram(const Harmonogram& _inny, Czas _to);

	Harmonogram& operator=(const Harmonogram& _inny);

	void dodajczas(const Czas _to);
	//void realokacja(const Czas *_to);
	void wyswietl();
	void wypisz_rozmiar();
	void wyswietl_czas(int _indeks);

	Czas sumuj_czasy();
	Czas zwroc_czas(int _indeks);

};