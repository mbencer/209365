#ifndef STOS_HH
#define STOS_HH
#include <iostream>
#include "Element.hh"
#include "Lista.hh"
/*!
 *\file
 *\brief Definicja klasy Stos
 *
 * Plik zawiera definicje klasy Stos, ktora bedzie
 * struktura naszych danych.
 * Klasa ta posiada szablon, dzieki czemu mozemy pracowac na 
 * roznych typach danych
 */


/*!
 * \brief Klasa Stos
 *
 * Klasa ta modeluje nam Stos
 * Składa się z pól klasy Lista (poczatek) ktore zostanie uzyta aby pokazywalo
 * na ostatni element stosu oraz metod PUSH, POP, SIZE, SHOW
 */
template<typename TYP>
class Stos: protected Lista<TYP>
{
    public:

/*
 * \brief Metoda PUSH()
 *
 *  Metoda ta służy do dodawania kolejnego elementu stosu, element dodajemy na
 * koniec
 * W funkcji PUSH pierwszy wskazuje na ostatni element stosu!!!!
 * Zastosowane w celu szybszego usuwania elementow stosu
 */
    void PUSH(TYP liczba)
    {	
	Element<TYP> * tmp = new Element<TYP>;
	tmp->wartosc = liczba;
	tmp->nastepny = this->pierwszy;
	this->pierwszy = tmp;
    }
/*
 * \brief Metoda POP()
 *
 *  Metoda ta służy do usuwania ostatniego elementu stosu zgodnie z LIFO
 * \return Funkcja zwraca 0 gdy metoda zostala wlasciwie uzyta, wartosc rozna od 0 w przypadku bledu
 */
    int POP(){return Lista<TYP>::POP(1);}
/*
 * \brief Metoda SHOW()
 *
 *  Metoda ta służy do wyswietlenia wszystkich elementow stosu
 *  Element na gorze stosu jest wyswietlany u gory
 *
 */
    void SHOW(){Lista<TYP>::SHOW();}

/*
 * \brief Metoda SIZE()
 *
 *  Metoda ta służy do podania nam liczby elementow na stosie
 *
 * \return Funkcja zwraca ilosc elementow stosu
 */
    unsigned int SIZE() {return Lista<TYP>::SIZE();}
	
};

#endif
