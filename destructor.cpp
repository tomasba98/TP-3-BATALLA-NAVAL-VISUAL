#include "destructor.h"

Destructor::Destructor()
{   Barco::setNum('4');
    Barco::setTamanio(4);
    Barco::setVida(4);
    Barco::setNombre("Destructor");
}
Destructor::Destructor(char ori, int v,int x, int y, int id, char t) : Barco (ori,v,x,y,id,t)
{   Barco::setNum('4');
    Barco::setTamanio(4);
    Barco::setVida(4);
    Barco::setNombre("Destructor");
}
