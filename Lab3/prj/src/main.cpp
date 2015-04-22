#include <iostream>
#include "Lista.hh"
#include "../inc/Benchmark.hh"
#include "../inc/Pivot.hh"
#include "../inc/quick_sort.hh"
#include "../inc/merge_sort.hh"

#include <cstdlib>
#include <cstdio>
#include <ctime>

// testowane rozmiary listy do posortowania
unsigned int test_list_sizes[] = {10, 100, 500, 1000, 5000, 10000, 30000, 50000, 80000};
unsigned int size = 9;
//ile pomiarów do średniej
unsigned int number_of_measurements=10;
//jakie sortowanie wybieramy w menu programu
enum SORT {QUICK_SORT=1, MERGE_SORT=2};

PIVOT pivot_choice();
SORT menu();


int main()
{
	Lista<int>* lista = new Lista<int>();
	Benchmark<int> bench(test_list_sizes, size,number_of_measurements);

	switch(menu()) {
		case QUICK_SORT: {
			bench.testQuickSort(lista, pivot_choice());
			break;
		}
		case MERGE_SORT: {
			bench.testMergeSort(lista);
			break;
		}
	}



return 0;
}

SORT menu() {
	int choice;
	std::cout<<"Jaki algorytm chcesz zbadac? \n"
			 <<"1. Quick Sort \n"
			 <<"2. Merge Sort \n";
	std::cin>>choice;

	return (SORT)choice;
}

PIVOT pivot_choice() {
	int option;
	std::cout<<"Jaka optymalizacje elementu osiowego wybierasz? \n"
			 <<"1. Pierwszy \n"
			 <<"2. Ostatni \n"
			 <<"3. Losowy \n"
			 <<"4. Srodkowy \n"
			 <<"5. Mediana z trzech \n";
	std::cin>>option;
	return (PIVOT)option;

}
