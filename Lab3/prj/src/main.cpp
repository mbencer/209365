#include <iostream>
#include "Lista.hh"
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Sortuj_szybko(int lewy, int prawy);
const int N=10;
int d[N];
int main()
{

srand((unsigned)time(NULL));
Lista<int> l;
for(int i = 0; i < N; i++) {
	l.PUSH(rand()%100);
}

for(int i = 0; i < N; i++) {
	d[i] = l.POP(1);
}
Sortuj_szybko(0,N - 1);

for(int i = 0; i < N; i++) {
l.PUSH(d[i]);
}

l.SHOW();

return 0;
}


void Sortuj_szybko(int lewy, int prawy)
{
  int i,j,piwot;

  i = (lewy + prawy) / 2;
  piwot = d[i]; d[i] = d[prawy];
  for(j = i = lewy; i < prawy; i++)
  if(d[i] < piwot)
  {
    swap(d[i], d[j]);
    j++;
  }
  d[prawy] = d[j]; d[j] = piwot;
  if(lewy < j - 1)  Sortuj_szybko(lewy, j - 1);
  if(j + 1 < prawy) Sortuj_szybko(j + 1, prawy);
}

