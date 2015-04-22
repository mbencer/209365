/*
 * merge_sort.hh
 *
 *  Created on: 18-04-2015
 *      Author: mateusz
 */

#ifndef MERGE_SORT_HH_
#define MERGE_SORT_HH_
#include "Lista.hh"
#include <iostream>

/**
\brief
funkcja do realizacji sortowania Merge Sort
*
*\param list lista, którą chcemy posortować
*\param size rozmiar listy, którą sortujemy
*\param low skarny lewy element listy
*\param high skarny prawy element listy
*/
template <class T>
void merge_sort(Lista<T>* list, int size, int low, int high);

/**
\brief
funkcja do realizające operacje scalania dwóch zbiorów (po prawej i lewej stronie middle) na potrzeby Merge Sort
*
*\param list lista, którą chcemy posortować
*\param size rozmiar listy, którą sortujemy
*\param low skarny lewy element listy
*\param middle środkowy element listy (on dzieli lista na zbiory do scalenia)
*\param high skarny prawy element listy
*/
template <class T>
void merge(Lista<T>* list, int size, int low, int middle, int high);



template <class T>
void merge_sort(Lista<T>* list, int size, int low, int high) {
	if(low<high) {
		int middle = (low+high)/2;
		merge_sort(list,size,low,middle);
		merge_sort(list,size,middle+1,high);
		merge(list,size,low, middle, high);
	}
}


template <class T>
void merge(Lista<T>* list, int size, int low, int middle, int high) {
	T* temp = new T[size];

	for(int i=low; i<= high; i++) {
		temp[i] = list->GET(i);

			}


	int i=low;
	int j=middle+1;
	int k=low;

	while( (i<=middle) && (j<=high) ) {
		if(temp[i] <= temp[j]) {
			list->SET(temp[i],k);
			++i;
		}
		else {
			list->SET(temp[j], k);
			++j;
		}
		++k;
	}

	while(i <= middle) {
		list->SET(temp[i],k);
		++k;
		++i;
	}
	delete[] temp;
}

#endif /* MERGE_SORT_HH_ */
