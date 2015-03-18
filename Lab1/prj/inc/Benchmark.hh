#ifndef BENCHMARK_HH
#define BENCHMARK_HH
#include <iostream>
/*!
 *\file
 *\brief Definicja klasy Benchmark
 *
 * Plik zawiera definicje klasy Benchmark ktora bedzie wyznaczala
 * nam punkty do wyznaczenia zlozonosci obliczeniowej.
 */
using namespace std;

/*!
 * \brief Klasa Benchmark
 *
 * Klasa ta modeluje nam test dla funkcji
 * Składa się z pól:
 * \param[in] _tablica_liczb - która przechowuje nasze dane ktorymi bedziemy testowali funkcje
 * \param[in] stoper_start - przechowuje poczatek mierzenia czasu
 * \param[in] iterator - sluzy nam do iterowania od 0 do 9 (10 prob) zatrzymania czasu
 * \param[in] iterator_sredniej - sluzy nam do iterowania kolejnego pomiaru 
 * sredniej w zaleznosci od ilosci prob 
 * \param[in] stoper_stop - przechowuje nam 10 wynikow pomiaru czasu (obliczony wynik jednego pomiaru)
 * \param[in] srednia_jednego_problemu - przechowuje tablice sredniego czasu wykonania pomiarow dla poszczegolnych prob
 * \param[in] ilosc_problemu - przechowuje nam jak duzo prob bedzie wykonywanych    
 * \param[in] Ilosc_Danych - ilosc danych na ktorych bedziemy pracowali     
 * \param[in] wielkosc_problemu - ilosc pojedynczego problemu(ilosci danych na 1 probe)
 */

class Benchmark
{
  int* _tablica_liczb;
  float stoper_start;
  unsigned int iterator;
  unsigned int iterator_sredniej;
  float* stoper_stop;
  float* srednia_jednego_problemu;
  unsigned int rozmiar_tablic;
/*
 * \brief Metoda Losuj()
 *
 *  Metoda ta służy do losowania wartosci dla naszej _tablica_liczb
 *
 * \param[in] _tablica_liczb - tablica liczb dla ktorej bedziemy losowali te wartosci
 * \param[in] rozmiar - rozmiar naszej tablicy (ile liczb bedziemy losowali)
 */
  void Losuj(int* tablica_liczb, unsigned int rozmiar);
/*
 * \brief Metoda Wczytaj_Dane()
 *
 *  Metoda ta służy do wczytania wartosci dla naszej _tablica_liczb, ktora tworzy wewnatrz, po przeliczeniu ilosci danych
 *
 * \return Funkcja zwraca ilosc danych w pliku
 *
 */
  unsigned int Wczytaj_Dane ();


  public:

/*!
 * \brief Inicjalizator klasy Benchmark
 *
 *  Inicjalizator ten służy do określania początkowych wartości
 *  pól klasy oraz wyboru na jakich danych bedziemy pracowali
 *  (losowe/wczytane)
 *
 * Opis argumentów:
 * \param[in] rozmiar_problemu - ilosc maksymalnej liczby wprowadzanych danych
 * \param[in] stala - stala przez ktora bedziemy mnozyli, aby np.uzyskac wiecej wynikow najlepszy przedzial (1.1-10)
 */
  Benchmark(unsigned int rozmiar_problemu, double stala);
  unsigned int* wielkosc_problemu;
  unsigned int Ilosc_Danych;
/*
 * \brief Metoda Tablica
 *
 *  Metoda ta służy do wygodnego pobierania wartości z _tablica_liczb
 *
 *  Zwracane wartości:
 *  \return Funkcja zwraca odpowiednie pole _tablica_liczb
 */
  double Tablica(int i) {return _tablica_liczb[i];}
/*
 * \brief Metoda Licz_Srednia()
 *
 *  Metoda ta służy do liczenia sredniego czasu wykonania jednego pomiaru dla
 *  okreslonej wielkosci problemu
 *  \return Funkcja zwraca odpowiednie pole srednia_jednego_problemu, 
 *   ktore jest odpowiednie dla danego problemu
 *
 */
  float Licz_Srednia();
/*
 * \brief Metoda Czas_Start()
 *
 *  Metoda ta służy do wlaczenia pomiaru czasu
 * \return Funkcja zwraca odpowiednie pole stoper_start, ktore nie jest tablica
 *  ze wzgledu na to ze dane nie beda nam uzyteczne
 */
  float Czas_Start();
/*
 * \brief Metoda Czas_Stop()
 *
 *  Metoda ta służy do zatrzymania pomiaru czasu.
 * \return Funkcja zwraca odpowiednie pole stoper_stop[i] ktore 
 *  pozniej zostanie uzyte podczas liczenia sredniej
 *
 */
  float Czas_Stop();
/*
 * \brief Metoda Zapisz_Wyniki()
 *
 *  Metoda ta służy do zapisania wynikow w postaci rozmiaru problemu 
 *  i odpowiadajacemu temu problemowi czasu. 
 *  Plik zostaje zapisany pod nazwa podana przez nas w formacie
 *  *.csv - do latwego przetworzenia danych w programie do wykresu.
 *  \return Funkcja zwraca jeden czas wykonania funkcji
 *
 */
  void Zapisz_Wyniki();



  ~Benchmark()
  {
     delete [] _tablica_liczb; 
     delete [] stoper_stop;
     delete [] wielkosc_problemu;
     delete [] srednia_jednego_problemu;
  }

};

#endif

