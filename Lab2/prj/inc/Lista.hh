#ifndef LISTA_HH
#define LISTA_HH
#include <iostream>

using namespace std;

/*!
 *\file
 *\brief Definicja klasy Lista
 *
 * Plik zawiera definicje klasy Lista ktora bedzie 
 */
template <typename TYP>

/*!
 * \brief Klasa Benchmark
 *
 * Klasa ta modeluje nam test dla funkcji
 * Składa się z pól:
 * \param[in] *nastepny - wskaznik na nastepny element listy; 
 */


class Lista 
{
	
	Lista *nastepny;
	Lista *poczatek;
	
	public:
	Lista(){poczatek=NULL;}

/*
 * \brief Metoda PUSH()
 *
 *  Metoda ta służy do dodawania kolejnego elementu listy
 *
 * \param[in] Lista *&poczatek - przekazanym przez referencje wskaznikiem na poczatek listy.
 * \param[in] zmienna - zmienne ktore bedziemy wrzucali typu ktory wybierzemy
 */
	TYP PUSH(TYP zmienna)
	{
	  Lista *tmp;
	  tmp = new Lista;
	  if(tmp == NULL) {cout<<"Brak Pamieci!!!\n"; return 1;}
	  tmp->zmienna = zmienna;
	  tmp->nastepny = poczatek;
	  poczatek = tmp;
	  return 0;
	}

	TYP POP();
	unsigned int SIZE()
	{
	  unsigned int ilosc_elementow=0;
	  while(poczatek)  
	  {
	    ilosc_elementow++;
	    poczatek = poczatek->naptepny;
	  }
	  return ilosc_elementow;
	}	
	
	TYP WYSWIETL();
	TYP zmienna;

};

#endif
