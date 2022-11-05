#include "submarino.h"

Submarino::Submarino()
{   Barco::setNum('7');
    Barco::setTamanio(3);
    Barco::setVida(3);
    Barco::setNombre("Submarino");
}
Submarino::Submarino(char ori, int v,int x, int y, int id, char t) : Barco (ori,v,x,y,id,t)
{   Barco::setNum('7');
    Barco::setTamanio(3);
    Barco::setVida(3);
    Barco::setNombre("Submarino");
}

