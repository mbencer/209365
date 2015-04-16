#include <iostream>
#include "Lista.hh"
#include "../inc/Benchmark.hh"
#include "../inc/Pivot.hh"
#include "../inc/quick_sort.hh"

unsigned int test_list_sizes[] = {10, 100, 500, 1000, 5000, 10000, 30000, 50000, 80000};
unsigned int size = 9;
unsigned int number_of_measurements=3;

PIVOT menu();

int main()
{

	Lista<int>* lista = new Lista<int>();
	Benchmark<int> bench(test_list_sizes, size,number_of_measurements);

	std::cout<<"Jaka optymalizacje elementu osiowego wybierasz? \n";

	bench.testQuickSort(lista, menu());

return 0;
}


PIVOT menu() {
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
