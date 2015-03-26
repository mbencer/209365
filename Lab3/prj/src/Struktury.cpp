#include <iostream>
#include "Lista.hh"
#include "Kolejka.hh"
#include "Stos.hh"

using namespace std;

int main()
{
Stos<int> l;
//Kolejka<int> l;
//Lista<int> l;
for(int i = 1; i<7;i++)
l.PUSH(i);
for(int i = 1; i<4;i++)
l.POP();
l.PUSH(3);

l.SHOW();
return 0;
}

