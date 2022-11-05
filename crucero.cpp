#include "crucero.h"

Crucero::Crucero()
{   Barco::setNum('3');
    Barco::setTamanio(3);
    Barco::setVida(3);
    Barco::setNombre("Crucero");
}
Crucero::Crucero(char ori, int v,int x, int y, int id, char t) : Barco (ori,v,x,y,id,t)
{   Barco::setNum('3');
    Barco::setTamanio(3);
    Barco::setVida(3);
    Barco::setNombre("Crucero");
}






