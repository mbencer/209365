#ifndef LISTA_HH
#define LISTA_HH
#include <iostream>
#include "Element.hh"
using namespace std;

/*!
 *\file
 *\brief Definicja klasy Lista
 *
 * Plik zawiera definicje klasy Lista, ktora bedzie
 * struktura naszych danych.
 * Klasa ta posiada szablon, dzieki czemu mozemy pracowac na 
 * roznych typach danych
 */


/*!
 * \brief Klasa Lista
 *
 * Klasa ta modeluje nam Liste
 * Składa się z metod PUSH, POP, SIZE, SHOW
 * oraz pól:
 * \param[in] *pierwszy - jako wskaznik na pierwszy element
 */
template<typename TYP>
class Lista 
{
	protected:
	Element<TYP> *pierwszy;
	Element<TYP> *ostatni;
	public:
	Lista(){ pierwszy = NULL; ostatni = NULL;}
	~Lista(){ delete pierwszy;}

/*
 * \brief Metoda PUSH()
 *
 *  Metoda ta służy do dodawania kolejnego elementu listy, element dodajemy na
 * koniec listy
 *
 * \param[in] liczba - zmienne ktore bedziemy wrzucali typu ktory wybierzemy
 */
void PUSH (TYP liczba)
{
Element<TYP> *tmp = new Element<TYP>;
tmp->wartosc = liczba;
if (ostatni==NULL) pierwszy = tmp; //ustawianie wkaznika do pierwszego elementu
else ostatni->nastepny = tmp;
ostatni = tmp;
}
/*
 * \brief Metoda POP()
 *
 *  Metoda ta służy do usuwania wybranego elementu listy
 * \param[in] Numer_Elementu - numer elementu który chcemy usunac
 * \return Funkcja zwraca 0 gdy metoda zostala wlasciwie uzyta, wartosc rozna od 0 w przypadku bledu
 */
int POP(unsigned int Numer_Elementu)
{
   if(Numer_Elementu <= 0 || Numer_Elementu > SIZE()) {cout<<"Nie ma elementu o numerze "<< Numer_Elementu<<". Byc moze został usuniety wczesniej!!!\n"; return 1;}
   unsigned int i = 1;
   Element<TYP> *wsk = pierwszy;
   Element<TYP> *usuwany;
   if(Numer_Elementu == 1) { pierwszy = wsk->nastepny; delete wsk; return 0;}

     while (wsk != NULL)          
       {
         if(i == Numer_Elementu-1)
         {
           usuwany = wsk->nastepny;
	   wsk->nastepny = usuwany->nastepny;
	   delete usuwany;
	   return 0;
         }
         wsk = wsk->nastepny;
         i++;
       }
return 2;
}
/*
 * \brief Metoda SIZE()
 *
 *  Metoda ta służy do podania nam liczby elementow na liscie
 *
 * \return Funkcja zwraca ilosc elementow listy
 */
unsigned int SIZE()
{
  if(pierwszy != NULL)
  {
    Element<TYP> *wsk = pierwszy;
    unsigned int i = 1;
    while( wsk->nastepny != NULL )         
      {
        wsk = wsk->nastepny;
        i++;
      }
    return i;
   } else return 0; 
}
/*
 * \brief Metoda SHOW()
 *
 *  Metoda ta służy do wyswietlenia wszystkich elementow listy
 *
 */
void SHOW()
{
   Element<TYP> *wsk = pierwszy;
   while(wsk)         
     {
     cout << wsk->wartosc << endl; 
     wsk = wsk->nastepny;
     }

}

};

#endif
