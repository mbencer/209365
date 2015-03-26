#include <iostream>
#include "Lista.hh"

using namespace std;

int main()
{
Lista<int> l;
for(int i = 1; i < 1000; i++)
l.PUSH(i);
l.Rozmiar();
cout<<"Rozmiar tablicy "<<l.SIZE()<<endl;
for(int i = 1; i < 1002; i++)
l.POP(1);
cout<<"Ilosc elementow "<<l.SIZE()<<endl;
l.Rozmiar();

l.SHOW();
for(int i = 1; i < 9; i++)
l.PUSH(i);
cout<<"Ilosc elementow "<<l.SIZE()<<endl;
l.Rozmiar();

l.SHOW();
return 0;
}

