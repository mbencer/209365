/**
*
\file
Benchmark.hh
*
\brief
Deklaracja i definicja (razem, bo szablon) klasy Benchmark
*/
#ifndef BENCHMARK_H_
#define BENCHMARK_H_
#include "../inc/Lista.hh"
#include "../inc/quick_sort.hh"
#include "../inc/Timer.hh"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

/**
\brief
Klasa do przeprowadzenia testów na kontenerach danych
*
*
Klasa odpwiada za pomiar czasu koniecznego do umieszczenia określonej liczby danych
na stosie, kolejce oraz liście
*/
template <class T>
class Benchmark {
private:
	unsigned int _numberOfMeasurements;
	unsigned int _numberTest;
	/**
	\brief
	* Liczby w tablicy określają jaką ilość danych (jak dużą listę) będziemy kolejno sortować
	* (w celu pomiaru poptrzebnego czasu dla każdej wielkości)
	*/
	unsigned int* _test_list_sizes;

	/**
	\brief
	Zmięnna służąca do pomiaru czasu potrzebnego na dodawanie elementów do kontenerów.
	*/
	Timer _timer;

	/**
	\brief
	Tablica zawierająca wyniki przeprowadzonych testów na poszczególnym kontenerze
	*/
	double* _resoults;


	/**
	\brief
	Metoda służąca do wypisywania wyników pomiarów
	*
	*\param container_name nazwa kontenera, dla które wyświetlone zostaną wyniki pomiarów
	*/

	void showResoults(std::string pivot);
	void fillList(Lista<T>* list, int list_size_index);
	Benchmark();
public:
	/**
	\brief
	Konstruktor klasy Benchmark pomiarający wykładnik liczby określającej dla jakiej liczby elementów testujemy kontener
	*
	*\param testPower Liczba określająca wykładnik 10. Cała liczba ( 10^(_testPower) ) określa
	liczbe elementów, które będą wkładane do kontenerów.
	*
	*\param Liczby w tablicy określają jaką ilość danych (jak dużą listę) będziemy kolejno sortować
	* (w celu pomiaru poptrzebnego czasu dla każdej wielkości)
	*/
	Benchmark(unsigned int* test_list_sizes, unsigned int size, unsigned int number_of_memeasurements);

	void testQuickSort(Lista<T>* list, PIVOT piv);



};

template <typename T>
Benchmark<T>::Benchmark(unsigned int* test_list_sizes, unsigned int size, unsigned int number_of_memeasurements) {
	_numberOfMeasurements=number_of_memeasurements;
	_numberTest = size;
	_test_list_sizes = new unsigned int[_numberTest];
	for(int i=0;i<_numberTest;i++) {
		_test_list_sizes[i] = test_list_sizes[i];
	}
	_resoults = new double[_numberTest];
}

template <typename T>
void Benchmark<T>::testQuickSort(Lista<T>* list, PIVOT piv) {

	for(int i=0;i<_numberTest;i++) {
		for(int j=0;j<_numberOfMeasurements;j++) {
			delete list;
			list = new Lista<T>();
			fillList(list, i);
			_timer.startTimer();
			quick_sort(list,1,list->SIZE(), piv);
			_timer.stopTimer();
			_resoults[i] += (_timer.diffTimeMs())/_numberOfMeasurements;
		}
	}

	switch(piv) {
	case FIRST:
		showResoults("FIRST");
		break;
	case LAST:
		showResoults("LAST");
		break;
	case RANDOM:
		showResoults("RANDOM");
		break;
	case CENTER:
		showResoults("CENTER");
		break;
	case MEDIAN_OF_THREE:
		showResoults("MEDIAN_OF_THREE");
		break;
	}

	}

template <typename T>
void Benchmark<T>::fillList(Lista<T>* list, int list_size_index) {
	srand((unsigned)time(NULL));
	for(int i=1;i<= _test_list_sizes[list_size_index];i++) {
		list->PUSH(rand()%MAX_RANDOM,i);
	}
}

template <typename T>
void Benchmark<T>::showResoults(std::string pivot) {
	std::cout<<"Quick sort,"<<" Pivot: "<<pivot<<" \n";
	for(int i=0;i<_numberTest;i++) {
		std::cout<<i+1<<". "<<" N="<<_test_list_sizes[i]<<" "<<_resoults[i]<<" ms \n";
	}
	std::cout<<"\n";
}



#endif /* BENCHMARK_H_ */
