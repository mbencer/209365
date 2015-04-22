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
#include "../inc/merge_sort.hh"
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
	/**
	\brief
	* Liczba pomiarów z których zostanie wyciągnięta średnia
	*/
	unsigned int _numberOfMeasurements;
	/**
	\brief
	* Ilość wymiarów listy dla której zostaną przeprowadzone testy
	*/
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
	Metoda służąca do wypisywania wyników pomiarów Quick Sort
	*
	*\param pivot element osiowy, użyty do sortowania
	*/
	void showResoultsQuick(std::string pivot);
	/**
	\brief
	Metoda służąca do wypisywania wyników pomiarów Merge Sort
	*
	*/
	void showResoultsMerge();
	/**
	\brief
	Metoda służąca do wypełniania listy liczbami pseudolosowymi
	*
	*\param list lista która zostanie wypełniona
	*\param list_size_index liczba będąca indeksem tablicy która przechowuje rozmiary do jakich ma zostać wypełniona lista
	*/
	void fillList(Lista<T>* list, int list_size_index);
	/**
	\brief
	Konstruktor klasy Benchamrk
	*
	*/
	Benchmark();
public:
	/**
	\brief
	Konstruktor klasy Benchmark
	*
	*\param test_list_sizes tablica przechowująca rozmiary list do testów
	*\param size liczba list równych rozmiarów do przetestowania
	*\param number_of_memeasurements liczba pomiarów branych do średniej
	*/
	Benchmark(unsigned int* test_list_sizes, unsigned int size, unsigned int number_of_memeasurements);

	/**
	\brief
	metoda do testowania algorytmu Quick Sort
	*
	*\param list lista na której testujemy sortowanie
	*\param piv jaką motedę wyboru elementu osiowego wybieramy
	*/
	void testQuickSort(Lista<T>* list, PIVOT piv);

	/**
	\brief
	metoda do testowania algorytmyu Merge Sort
	*
	*\param list lista na której testujemy sortowanie
	*/
	void testMergeSort(Lista<T>* list);



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
		showResoultsQuick("FIRST");
		break;
	case LAST:
		showResoultsQuick("LAST");
		break;
	case RANDOM:
		showResoultsQuick("RANDOM");
		break;
	case CENTER:
		showResoultsQuick("CENTER");
		break;
	case MEDIAN_OF_THREE:
		showResoultsQuick("MEDIAN_OF_THREE");
		break;
	}

	}

template <typename T>
void Benchmark<T>::testMergeSort(Lista<T>* list) {
	for(int i=0;i<_numberTest;i++) {
		for(int j=0;j<_numberOfMeasurements;j++) {
			delete list;
			list = new Lista<T>();
			fillList(list, i);
			_timer.startTimer();
			merge_sort(list,list->SIZE()+1,1,list->SIZE());
			_timer.stopTimer();
			_resoults[i] += (_timer.diffTimeMs())/_numberOfMeasurements;
		}
	}

	showResoultsMerge();

}

template <typename T>
void Benchmark<T>::fillList(Lista<T>* list, int list_size_index) {
	srand((unsigned)time(NULL));
	for(int i=1;i<= _test_list_sizes[list_size_index];i++) {
		list->PUSH(rand()%MAX_RANDOM,i);
	}
}

template <typename T>
void Benchmark<T>::showResoultsQuick(std::string pivot) {
	std::cout<<"Quick sort,"<<" Pivot: "<<pivot<<" \n";
	for(int i=0;i<_numberTest;i++) {
		std::cout<<i+1<<". "<<" N="<<_test_list_sizes[i]<<" "<<_resoults[i]<<" ms \n";
	}
	std::cout<<"\n";
}

template <typename T>
void Benchmark<T>::showResoultsMerge() {
	std::cout<<"Merge Sort: \n";
	for(int i=0;i<_numberTest;i++) {
		std::cout<<i+1<<". "<<" N="<<_test_list_sizes[i]<<" "<<_resoults[i]<<" ms \n";
	}
	std::cout<<"\n";
}



#endif /* BENCHMARK_H_ */
