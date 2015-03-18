#include "Benchmark.hh"
#include <cstdlib>
#include <fstream>
#include <ctime>

/*!
 * \file
 * \brief Metody klasy Benchmark
 *
 * Plik zawiera definicje metod klasy Benchmark
 */

using namespace std;

  Benchmark::Benchmark(unsigned int rozmiar_problemu,double STALA)
  {	
	int i;
        iterator=0;
	iterator_sredniej = 0;
	cout<<"Wczytanie losowych wartosci wybierz 1.\nWczytanie z pliku wybierz 2.\n";
	cin>>i;
	switch(i)
	{ 
	 case 1:
	   Ilosc_Danych = rozmiar_problemu;
	   _tablica_liczb = new int [rozmiar_problemu];
	   Losuj(_tablica_liczb, rozmiar_problemu);
	   break;
         //Tablica zawierajaca liczby tworzy sie po otwarciu i zliczeniu danych(ile jest ich w pliku)
	 case 2:
	   if((Ilosc_Danych = Wczytaj_Dane()) == 0)
	   {
	     cout<<"Blad, plik byl pusty\n";
	     exit(1);
	   }
	   break;

	 default:
	     cout<<"Bledny wybor, koniec testu!!!\n";
	     exit(2);
	   break;
	}
	int rozmiar_tablic = 0;
  	for(unsigned int i=10; i <= Ilosc_Danych; i*=STALA)
    	    rozmiar_tablic++;


	stoper_stop = new float[10]; //czas 10 pomiarow
        wielkosc_problemu = new unsigned int[rozmiar_tablic];
        srednia_jednego_problemu = new float[rozmiar_tablic];
	
  }



void Benchmark::Losuj(int* tablica_liczb, unsigned int rozmiar)
{
	for (unsigned int i = 0; i < rozmiar; ++i)
	{
		tablica_liczb[i] = rand();
	}
}



float Benchmark::Czas_Start()
{	
	clock_t poczatek = clock(); //Start pomiaru
	stoper_start = poczatek; 
	return this->stoper_start;
}

float Benchmark::Czas_Stop()
{
	if(this->iterator == 10) this->iterator = 0;
	float czas_wykonania = clock()-this->stoper_start; //Obliczenie czasu wykonania
	this->iterator +=1; 
	czas_wykonania = (float)czas_wykonania/CLOCKS_PER_SEC; //Zamiana czasu na sekundy
	stoper_stop[iterator-1] = czas_wykonania;
	return this->stoper_stop[iterator-1];
}

float Benchmark::Licz_Srednia()
{
	float srednia = 0;
	
	for(unsigned int i = 0; i < 10; i++)
	   srednia += stoper_stop[i]; //sumowanie 
	srednia_jednego_problemu[iterator_sredniej] = srednia/10; //Podzielone przez 10 ze wzgledu ze bylo 10 prob
	iterator_sredniej++;
	cout<<srednia_jednego_problemu[iterator_sredniej-1]<<"\n";
	return srednia_jednego_problemu[iterator_sredniej-1];
}

void Benchmark::Zapisz_Wyniki()
{

    string nazwa_pliku;
    cout<<"Podaj nazwe pliku do zapisania(bez rozszerzenia): ";
    cin>>nazwa_pliku;
    nazwa_pliku+=".csv";
    fstream plik;
    plik.open( nazwa_pliku.c_str(), ios::out );
    if( plik.good() == true )
    {  
	plik<<"Ilosc danych"<<","<<"Czas [s]"<<endl;
	for (unsigned int i = 0; i < this->rozmiar_tablic; ++i)
          plik<< this->wielkosc_problemu[i]<<","<<this->srednia_jednego_problemu[i]<<endl;
	plik<<endl;
        plik.close();
    }else cout << "Dostep do pliku zostal zabroniony!" <<endl;
}


unsigned int Benchmark::Wczytaj_Dane ()
{
    unsigned int i = 0;//zmienna zliczajaca ilosc danych w 
    double bufor;//zmienna tymczasowa na dane
    string nazwa_pliku;
    cout<<"Podaj nazwe pliku do wczytania: ";
    cin>>nazwa_pliku;
    fstream plik;
    plik.open( nazwa_pliku.c_str() ,ios::in );
    if( !plik.good() )
    {    
         cout<<"\nNie udało sie otworzyc pliku :(\n";
         return 0; //Nie udało się otworzyć pliku
    }

    while( !plik.eof() )
    {
       
      plik>>bufor;//sluzy tylko do zliczenia danych
      i++;
        if( plik.bad() )
        {
            cout<<"\nNie udało sie otworzyc pliku, blad sprzetowy :(\n";
            plik.close();
            return 0; //wychodzimy z funkcji i informujemy, że odczytanie pliku zakończyło się niepowodzeniem
        }
        
    }
    plik.clear();//Czysci flagi naszego pliku
    plik.seekg(0,ios_base::beg);//przesuwam karetke na poczatek
    _tablica_liczb = new int[i-1];// i-1 poniewaz i sie zinkrementuje o jeden raz za duzo
    for(unsigned int j = 0; j < i-1; j++)
      plik >> this->_tablica_liczb[j];
      
    plik.close();
    return i-1;
}


