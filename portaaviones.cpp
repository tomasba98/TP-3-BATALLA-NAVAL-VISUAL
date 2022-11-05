#include "portaaviones.h"

Portaaviones::Portaaviones()
{   Barco::setNum('5');
    Barco::setTamanio(5);
    Barco::setVida(5);
    Barco::setNombre("Portaaviones");
}
Portaaviones::Portaaviones(char ori, int v,int x, int y, int id, char t) : Barco (ori,v,x,y,id,t)
{   Barco::setNum('5');
    Barco::setTamanio(5);
    Barco::setVida(5);
    Barco::setNombre("Portaaviones");
}
