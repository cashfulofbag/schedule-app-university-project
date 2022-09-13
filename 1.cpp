#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"

int main()
{
	int x, s, g, m;
	Czas wynik;
	bool y;
	int wyb = 0;
	
	Czas c1(0, 16, 20);
	Czas c2(0, 40, 78);
	Czas c3(2, 55, 400);
	Czas c4(70, 55);
	Czas c5(200);
	Czas czas_dodany;
	
	Harmonogram h1;
	Harmonogram& refh1 = h1;
	h1.dodajczas(c1);
	h1.dodajczas(c2);
	h1.dodajczas(c3);
	h1.dodajczas(c4);
	h1.dodajczas(c5);

	h1.wyswietl();

	std::cout << "Do ktorego czasu chcesz dodac sekundy?" << std::endl;
	std::cin >> wyb;
	std::cout << "Ile sekund chcesz dodac?" << std::endl;
	std::cin >> s;
	
	wynik = h1.zwroc_czas(wyb);
	wynik = wynik + s;
	h1.tab[wyb] = wynik;
	h1.wyswietl();

	Harmonogram h4(refh1);
	std::cout << "Skopiowany harmonogram :" << std::endl;
	h4.wyswietl();

	std::cout << "Do ktorego czasu chcesz skopiowac (podaj indeks)" << std::endl;
	std::cin >> wyb;
	Harmonogram h2(refh1, wyb);
	std::cout << "Skopiowany harmonogram :" << std::endl;
	h2.wyswietl();

	std::cout << "Do ktorego czasu chcesz skopiowac (podaj czas)" << std::endl;
	std::cout << "godziny:";
	std::cin >> g;
	std::cout << "minuty:";
	std::cin >> m;
	std::cout << "sekundy:";
	std::cin >> s;
	Czas c6(g, m, s);
	Harmonogram h3(refh1, c6);
	std::cout << "Skopiowany harmonogram :" << std::endl;
	h3.wyswietl();
	



	/*while (wyb != 9) //menu harmonogramu
	{
		std::cout << "1.Wyswietl czasy z harmonogramu" << std::endl;
		std::cout << "2.Wyswietl rozmiar harmonogramu" << std::endl;
		std::cout << "3.Kopiuj harmonogram do indeksu" << std::endl;
		std::cout << "4.Kopiuj harmonogram do wartosci czasu" << std::endl;
		std::cout << "9.Wyjdz" << std::endl;
		std::cin >> wyb;
		switch (wyb)
		{
		case 1:
			h1.wyswietl();
			while (wyb != 9)	//menu czasów
			{
				std::cout << "1.Sumuj czasy harmonogramu" << std::endl;
				std::cout << "2.Wyswietl czas z harmonogramu" << std::endl;
				std::cout << "9.Wyjdz" << std::endl;
				std::cin >> wyb;
				switch (wyb)
				{
				case 1:
					wynik = h1.sumuj_czasy();
					wynik.wypisz_czas();
					break;
				case 2:
					int indeks;
					std::cout << "Ktory czas wyswietlic?";
					std::cin >> indeks;
					h1.wyswietl_czas(indeks);
					
					std::cout << "Czy chcesz dodac do tego czasu?" << std::endl;
					std::cout << "1.Tak" << std::endl;
					std::cout << "2.Nie" << std::endl;
					
					std::cin >> wyb;
					switch (wyb)
					{
					case 1:
						int s;
						std::cout << "Ile sekund chcesz dodac?" << std::endl;
						std::cin >> s;
						wynik = h1.zwroc_czas(indeks);
						wynik = wynik + s;
						break;
					case 2:
						break;
					default:
						break;
					}
					break;
				case 9:
					break;
				default:
					std::cout << "Wybrano niewlasciwa opcje" << std::endl;
					break;
				}

			}
			wyb = 0;
			break;
		case 2:
			h1.wypisz_rozmiar();
			break;
		case 3:
			int indeks;

			std::cout << "Do ktorego czasu chcesz skopiowac: ";
			std::cin >> indeks;
			//Harmonogram h2(refh1, indeks);
			//std::cout << "Skopiowane czasy to: " << std::endl;
			//h2.wyswietl();

			break;
			
		case 4:
			break;
		case 9:
			break;

		default:
			std::cout << "Wybrano niewlasciwa opcje" << std::endl;
			break;

		}
	}*/

	return 0;
}