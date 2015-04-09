#include "Lista.hh"

template <class T>
void swap ( Lista<T>* list, int index_a, int index_b );

template <typename T>
void quick_sort(Lista<T>* list, int left, int right)
{
	  int i,j,piwot;

	  i = (left + right) / 2;
	  piwot = list->GET(i);
	  list->SET(list->GET(right),i);
	  for(j = i = left; i < right; i++) {
	  if(list->GET(i) < piwot)
	  {
	    swap(list, i, j);
	    j++;
	  }
	  }
	  list->SET(list->GET(j),right);
	  list->SET(piwot,j);

	  if(left < j - 1)  quick_sort(list, left, j - 1);
	  if(j + 1 < right) quick_sort(list, j + 1, right);
}

template <class T>
void swap ( Lista<T>* list, int index_a, int index_b )
{
	T temp = list->GET(index_a);
	list->SET(list->GET(index_b),index_a);
	list->SET(temp,index_b);
}
