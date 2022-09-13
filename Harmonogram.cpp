#include "Harmonogram.h"
#include <iostream>

Harmonogram::Harmonogram()
	: rozmiar(0)
	, tab(nullptr)
{

}

Harmonogram::Harmonogram(const Czas _to)
	:rozmiar(1)
	, tab(new Czas[rozmiar])
{
	tab[0] = _to;
}

Harmonogram::~Harmonogram()
{
	delete[] tab;
}

Harmonogram::Harmonogram(const Harmonogram& _inny, int _ilosc)
{
	rozmiar = _ilosc;
	tab = new Czas[_ilosc];
	for (int x = 0; x < _ilosc; x++)
	{
		tab[x] = _inny.tab[x];
	}
}

Harmonogram::Harmonogram(const Harmonogram& _inny)
{
	rozmiar = _inny.rozmiar;
	tab = new Czas[rozmiar];
	for (int x = 0; x < rozmiar; x++)
	{
		tab[x] = _inny.tab[x];
	}
}

Harmonogram::Harmonogram(const Harmonogram& _inny, Czas _to)
{
	Czas suma;
	int x;
	for (x = 0; x < _inny.rozmiar; x++)
	{
		if (suma < _to)
		{
			suma = suma + _inny.tab[x];
		}
		else
		{
			break;
		}
	}
	rozmiar = x;
	tab = new Czas[rozmiar];
	for (int x = 0; x < rozmiar; x++)
	{
		tab[x] = _inny.tab[x];
	}
}

Harmonogram& Harmonogram::operator=(const Harmonogram& _inny)
{
	if (&_inny == this) return *this;
	delete[] tab;
	rozmiar = _inny.rozmiar;
	tab = new Czas[rozmiar];
	for (int x = 0; x < rozmiar; x++)
	{
		tab[x] = _inny.tab[x];
	}
	return *this;
}

void Harmonogram::dodajczas(const Czas _to)
{
	Czas* ntab;
	ntab = new Czas[rozmiar];

	for (int y = 0; y < this->rozmiar; y++)
	{
		ntab[y] = tab[y];
	}
	
	delete[] this->tab;
	
	tab = new Czas[(this->rozmiar + 1)];
	for (int y = 0; y < this->rozmiar; y++)
	{
		tab[y] = ntab[y];
	}
	delete[] ntab;
	this->rozmiar++;
	tab[rozmiar - 1] = _to;
}

void Harmonogram::wyswietl()
{
	for (int x = 0; x < rozmiar; x++)
	{
		std::cout<< x << ". ";
		this->tab[x].wypisz_czas();
	}
}

void Harmonogram::wypisz_rozmiar()
{
	std::cout <<"Harmonogram ma " << this->rozmiar << " czasow" << std::endl;
}

void Harmonogram::wyswietl_czas(int _indeks)
{
	if (_indeks > this->rozmiar || _indeks < 0)
	{
		std::cout << "Nie ma takiego czasu" << std::endl;
	}
	else
	{
		std::cout << _indeks << ". ";
		this->tab[_indeks].wypisz_czas();
	}

}

Czas Harmonogram::sumuj_czasy()
{
	Czas suma;
	
	for (int x = 0; x < rozmiar; x++)
	{
		suma = suma + this->tab[x];
	}
	return suma;
}

Czas Harmonogram::zwroc_czas(int _indeks)
{
	return this->tab[_indeks];
}

