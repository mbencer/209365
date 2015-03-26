#ifndef STOS_HH
#define STOS_HH
#include <iostream>
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
 * Składa się z pól klasy Lista ktore zostania uzyte oraz metod PUSH, POP, SIZE, SHOW
 * Klasa w calosci wykorzystuje implementacje listy
 */
template<typename TYP>
class Stos: protected Lista<TYP>
{
    public:

/*
 * \brief Metoda PUSH()
 *
 *  Metoda ta służy do dodawania kolejnego elementu kolejki, element dodajemy na
 * koniec kolejki
 */
    void PUSH(TYP liczba){Lista<TYP>::PUSH(liczba);}
/*
 * \brief Metoda POP()
 *
 *  Metoda ta służy do usuwania ostatniego elementu stosu zgodnie z LIFO
 * \return Funkcja zwraca 0 gdy metoda zostala wlasciwie uzyta, wartosc rozna od 0 w przypadku bledu
 */
    int POP(){return Lista<TYP>::POP(SIZE());}
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
