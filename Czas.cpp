#include "Czas.h"

Czas::Czas(int _h, int _m, int _s)
	:sekundy(_s)
	, minuty(_m)
	, godziny(_h)

{
	Czas& ref1 = *this;
	sprawdz(_h, _m, _s, ref1);
}

Czas::Czas(int _m, int _s)
	:sekundy(_s)
	, minuty(_m)
	, godziny(0)

{
	Czas& ref1 = *this;
	sprawdz(ref1.godziny, _m, _s, ref1);
}

Czas::Czas(int _s)
	:sekundy(_s)
	, minuty(0)
	, godziny(0)
{
	Czas& ref1 = *this;
	sprawdz(ref1.godziny, ref1.minuty, _s, ref1);
}

Czas::Czas()
	:sekundy(0)
	, minuty(0)
	, godziny(0)
{

}


int Czas::podajstan_s()
{
	return sekundy;
}

int Czas::podajstan_m()
{
	return minuty;
}

int Czas::podajstan_h()
{
	return godziny;
}

void Czas::ustawstan_s(int _ile)
{
	sekundy = _ile;
}

void Czas::ustawstan_m(int _ile)
{
	minuty = _ile;
}

void Czas::ustawstan_h(int _ile)
{
	godziny = _ile;
}

/*int Czas::ustawstan(int _h, int _m, int _s, Czas& _to)
{
	int x;
	
	_to.godziny = _h;
	_to.minuty = _m;
	_to.sekundy = _s;
	
	x = sprawdz_s(_s, _to);
	if (x == 0)
	{
		return 0;
	}
	x = sprawdz_m(_m, _to);
	if(x == 0)
	{
		return 0;
	}
	sprawdz_h(_h, _to);
	if (x == 0)
	{
		return 0;
	}
	
	return 1;
}

int Czas::ustawstan(int _m, int _s, Czas& _to)
{
	int x;

	_to.minuty = _m;
	_to.sekundy = _s;

	x = sprawdz_s(_s, _to);
	if (x == 0)
	{
		return 0;
	}
	x = sprawdz_m(_m, _to);
	if (x == 0)
	{
		return 0;
	}
	x = sprawdz_h(_to.godziny, _to);
	if( x == 0)
	{
		return 0;
	}

	return 1;
}

int Czas::ustawstan(int _s, Czas& _to)
{
	int x;

	_to.sekundy = _s;

	x = sprawdz_s(_s, _to);
	if (x == 0)
	{
		return 0;
	}
	x = sprawdz_m(_to.minuty, _to);
	if (x == 0)
	{
		return 0;
	}
	x = sprawdz_h(_to.godziny, _to);
	if (x == 0)
	{
		return 0;
	}

	return 1;
}*/

int Czas::sprawdz(int _h, int _m, int _s, Czas& _to)
{

	_to.godziny = _h;
	_to.minuty = _m;
	_to.sekundy = _s;

	sprawdz_s(_to.sekundy, _to);
	sprawdz_m(_to.minuty, _to);
	sprawdz_h(_to.godziny, _to);

	return 1;
}

int Czas::sprawdz_s(int _ile, Czas& _to)
{
	int x, y;
	if (_ile < 0)
	{
		std::cout << "Podanao ujemny czas zmieniam wartosc na 0" << std::endl;
		_to.ustawstan_s(0);
	}
	if (_ile > 59)
	{
		x = _to.podajstan_s();
		y = _to.podajstan_m();
		x = x - 60;
		y++;
		_to.ustawstan_m(y);
		_to.ustawstan_s(x);
		_to.sprawdz_s(x, _to);
	}
	return 1;
}

int Czas::sprawdz_m(int _ile, Czas& _to)
{
	int x;
	int y;
	if (_ile < 0)
	{
		std::cout << "Podanao ujemny czas zmieniam wartosc na 0" << std::endl;
		_to.ustawstan_m(0);
	}
	if (_ile > 59)
	{
		x = _to.podajstan_m();
		y = _to.podajstan_h();
		x = x - 60;
		y++;
		_to.ustawstan_h(y);
		_to.ustawstan_m(x);
		_to.sprawdz_m(x, _to);
	}
	return 1;
}

int Czas::sprawdz_h(int _ile, Czas& _to)
{
	int x;
	if (_ile < 0)
	{
		std::cout << "Podanao ujemny czas zmieniam wartosc na 0" << std::endl;
		_to.ustawstan_h(0);
	}
	return 1;
}

void Czas::wypisz_czas()
{
	std::cout << "Czas: " <<  (*this).podajstan_h() << ":" << (*this).podajstan_m() << ":" << (*this).podajstan_s() << std::endl;
}

Czas Czas::operator+(Czas _to)
{
	Czas temp = _to;
	Czas& reftemp = temp;
	temp.godziny += godziny;
	temp.minuty += minuty;
	temp.sekundy += sekundy;
	
	sprawdz_s(temp.sekundy, reftemp);
	sprawdz_m(temp.minuty, reftemp);
	sprawdz_h(temp.godziny, reftemp);
	
	return temp;
}

Czas Czas::operator+(int _liczba)
{
	Czas temp;
	Czas& reftemp = temp;

	temp.sekundy = sekundy + _liczba;
	temp.minuty = minuty;
	temp.godziny = godziny;

	sprawdz_s(temp.sekundy, reftemp);
	sprawdz_m(temp.minuty, reftemp);
	sprawdz_h(temp.godziny, reftemp);

	return temp;
}

bool Czas::operator==(Czas _to)
{
	Czas temp = _to;
	if ((godziny == temp.godziny) && (minuty == temp.minuty) && (sekundy == temp.sekundy))
		return true;
	else
		return false;
	
}

bool Czas::operator<(Czas _to)
{
	Czas temp = _to;
	if (godziny > temp.godziny)
		return false;

	else if ((godziny == temp.godziny) && (minuty > temp.minuty))
		return false;

	else if ((minuty == temp.minuty) && (sekundy > temp.sekundy))
		return false;
	else
		return true;
}
