#include <iostream>

#include "Benchmark.hh"
#define STALA 5 //wspolczynnik przez ktory bedzie liczona ilosc pomiarow
// i=10; w kolejnym kroku i*=5, aż do uzyskania mniejszej liczby niz nasza ilosc danych

double funkcja(double x){ int y; y=2*x; return y;} //Funkcja mnozaca nasze dane przez 2

using namespace std;

int main()
{
unsigned int WIELKOSC_PROBLEMU = 100000000; //Ilosc naszych danych
int iterator = 0;

Benchmark test(WIELKOSC_PROBLEMU, STALA);

WIELKOSC_PROBLEMU = test.Ilosc_Danych; //Jesli było wczytanie z pliku


  for(unsigned int i=10; i <= WIELKOSC_PROBLEMU; i*=STALA)
    {
       test.wielkosc_problemu[iterator] = i;
       iterator++;

      for(unsigned int j = 0; j < 10; ++j)
      {  
	test.Czas_Start();
	for(unsigned int k = 0; k < i; ++k)//Petla nadajaca kolejne wartosci do funkcji
	{
		funkcja(test.Tablica(k));
		
	}
	test.Czas_Stop();
	
      }
      test.Licz_Srednia();
        
    } 
test.Zapisz_Wyniki();
return 0;
}
