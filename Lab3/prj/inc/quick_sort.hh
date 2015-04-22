/*
 * quick_sort.hh
 *
 *  Created on: 16-04-2015
 *      Author: mateusz
 */

#ifndef QUICK_SORT_HH_
#define QUICK_SORT_HH_
#include "../inc/Pivot.hh"
#include "Lista.hh"

#include <cstdlib>
#include <cstdio>
#include <ctime>

#define MAX_RANDOM 100000

/**
\brief
funkcja do zamiany lelemtów miejscami
*
*\param list lista w której zamieniamy elementy
*\param index_a pozycja pierwszego elementu, którego pozycję zamieniamy z drugim
*\param index_a pozycja jdrugiego elementu, którego pozycję zamieniamy z pierszym
*/
template <class T>
void swap ( Lista<T>* list, int index_a, int index_b );

/**
\brief
funkcja do realizacji sortowania Quick Sort
*
*\param list lista, którą chcemy posortować
*\param left skarny lewy element wyznaczający zakres sortowania
*\param right skrajny prawy element wyznaczjący zakres sortowania
*\param piv określa jaki element osiowy wybieramy podczas sortowania
*/
template <typename T>
void quick_sort(Lista<T>* list, int left, int right, PIVOT piv);


template <typename T>
void quick_sort(Lista<T>* list, int left, int right, PIVOT piv)
{
	int i,j,pivot, center;
	center = (left + right) / 2;
	srand((unsigned)time(NULL));


	switch(piv) {
	case FIRST: {
		i = left;
		break;
	}
	case LAST: {
		i = right;
		break;
	}

	case RANDOM: {
		i = rand()%list->SIZE();
		break;
	}

	case CENTER: {
		i = (left + right) / 2;
		break;
	}

	case MEDIAN_OF_THREE: {
		if( (list->GET(left)>=list->GET(center) && list->GET(left)<=list->GET(right))
		||  (list->GET(left)<=list->GET(center) && list->GET(left)>=list->GET(right))) {
			i = left;
		}

		if( (list->GET(center)>=list->GET(left) && list->GET(center)<=list->GET(right))
		||  (list->GET(center)<=list->GET(left) && list->GET(center)>=list->GET(right))) {
			i = center;
		}

		if( (list->GET(right)>=list->GET(left) && list->GET(right)<=list->GET(center))
		||  (list->GET(right)<=list->GET(left) && list->GET(right)>=list->GET(center))) {
			i = right;
		}


		break;
	}

	}

	  pivot = list->GET(i);
	  list->SET(list->GET(right),i);
	  for(j = i = left; i < right; i++) {
	  if(list->GET(i) < pivot)
	  {
	    swap(list, i, j);
	    j++;
	  }
	  }
	  list->SET(list->GET(j),right);
	  list->SET(pivot,j);

	  if(left < j - 1)  quick_sort(list, left, j - 1,piv);
	  if(j + 1 < right) quick_sort(list, j + 1, right,piv);
}

template <class T>
void swap ( Lista<T>* list, int index_a, int index_b )
{
	T temp = list->GET(index_a);
	list->SET(list->GET(index_b),index_a);
	list->SET(temp,index_b);
}


#endif /* QUICK_SORT_HH_ */
