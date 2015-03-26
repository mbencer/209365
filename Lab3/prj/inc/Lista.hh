#ifndef LISTA_HH
#define LISTA_HH
#include <iostream>

using namespace std;

/*!
 *\file
 *\brief Definicja klasy Lista
 *
 * Plik zawiera definicje klasy Lista ktora bedzie struktura
 * danych oparta na tablicy dynamicznej
 */


/*!
 * \brief Klasa Lista
 *
 * Klasa ta modeluje nam Liste wartosci typu TYP
 * Składa się z pól:
 * \param[in] *tab - tablica naszych liczb; 
 * \param[in] poczatek - pierwsza liczba w naszej tablicy
 * \param[in] koniec - ostatnia liczba w naszej tablicy
 * \param[in] _rozmiar_listy - rozmiar stworzonej tablicy dynamicznej
 */
template<typename TYP>
class Lista 
{
	
	TYP *tab;
	unsigned int _rozmiar_listy;//rozmiar calej tablicy
        unsigned int poczatek;//pierwszy element
	unsigned int koniec;//ostatni element
	
	public:
        void Rozmiar(){cout<<"Rozmiar tablicy dyn: "<<_rozmiar_listy<<endl;}
	Lista(){ tab = new TYP [5]; _rozmiar_listy = 5; poczatek = 0; koniec = 0;}
	~Lista(){ delete [] tab;}

/*
 * \brief Metoda PUSH()
 *
 *  Metoda ta służy do dodawania kolejnego elementu do listy. Element dodajemy na koncu listy.
 *
 * \param[in] liczba - zmienne ktore bedziemy wrzucali, typu ktory wybierzemy
 */
void PUSH (TYP liczba)
{
   if(koniec < _rozmiar_listy)
   {
     tab[koniec] = liczba;
     koniec++;
    
   } else 
   {
     Powiekszenie_Pamieci();
     tab[koniec] = liczba;
     koniec++;
   }
   
}
//ile nowych komorek
void Powiekszenie_Pamieci()
{
  TYP* NoweDane = new TYP [_rozmiar_listy+1];
  _rozmiar_listy+=1;
  for( int i = poczatek; i < koniec; i++ ) NoweDane[ i ] = tab[ i ];
  if( tab != NULL ) delete[] tab; //zwolnij pamięć zajmowaną przez stare dane
  tab = NoweDane; //nadaj nowy wskaźnik zmiennej tablica
}
void Zmniejszenie_Pamieci()
{

  if(_rozmiar_listy/2 >= 5) //jesli tablica po pomniejszeni bedzie wieksza od 5 to zmniejsz pamiec
  {
  TYP* NoweDane = new TYP [_rozmiar_listy/2];
  _rozmiar_listy/=2;
  int iterator = 0; 
  for( int i = poczatek; i < koniec; i++ ) {NoweDane[ iterator ] = tab[ i ]; iterator++;}
  if( tab != NULL ) delete[] tab; //zwolnij pamięć zajmowaną przez stare dane
  tab = NoweDane; //nadaj nowy wskaźnik zmiennej tablica
  koniec = koniec-poczatek;
  poczatek = 0;
  }

}
/*
 * \brief Metoda POP()
 *
 *  Metoda ta służy do usuwania elementu listy. 
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Mozemy usunac pierwszy element wpisujac 1 lub ostatni element uzywajac metody SIZE()
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * \param[in] liczba - numer elementu który chcemy usunac, pierwszy 1, ostatni metoda SIZE()
 * \return Funkcja zwraca 0 gdy metoda zostala wlasciwie uzyta, wartosc rozna od 0 w przypadku bledu
 */
int POP (int liczba)
{
   if (SIZE() == 0) {cout<<"Tablica pusta !!!"<<endl; return 1;}
   if(SIZE()*4 <= _rozmiar_listy) Zmniejszenie_Pamieci();
   if(liczba == 1) {poczatek++; return 0;}
    else if(liczba == SIZE()) {koniec--; return 0;}
     else {cout<<"Niepoprawny wybor usuniecia elementu!!!"<<endl; return 2;}
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
  return koniec-poczatek;
}
/*
 * \brief Metoda SHOW()
 *
 *  Metoda ta służy do wyswietlenia wszystkich elementow listy
 *
*/

void SHOW()
{
  for( int i = poczatek; i < koniec; i++ ) cout<<tab[i]<<endl;
}

};

#endif
