#include <iostream>
#include "Lista.hh"
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "quick_sort.cpp"

using namespace std;

const int N=10;

int main()
{

srand((unsigned)time(NULL));
Lista<int> l;
for(int i = 1; i <= N; i++) {
	l.PUSH(rand()%100,i);
}
l.SHOW();
cout<<"SORT: \n";
quick_sort(&l, 1,N);

l.SHOW();
//cout<<"\n-------\n";

//for(int i = l.SIZE(); i >= 1; i--) {
//	cout<<l.POP(i)<<"\n";
//}

return 0;
}


