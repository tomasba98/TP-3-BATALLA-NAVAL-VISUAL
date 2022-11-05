#include "lancha.h"
#include <stdlib.h>
#include <time.h>

Lancha::Lancha()
{   Barco::setNum('1');
    Barco::setTamanio(1);
    Barco::setVida(1);
    Barco::setNombre("Lancha");
}
Lancha::Lancha(char ori, int v,int x, int y, int id, char t) : Barco (ori,v,x,y,id,t)
{   Barco::setNum('1');
    Barco::setTamanio(1);
    Barco::setVida(1);
    Barco::setNombre("Lancha");
}

