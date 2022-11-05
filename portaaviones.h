#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H
#include "barco.h"

class Portaaviones : public Barco
{
public:
    Portaaviones();
    Portaaviones(char ori, int v,int x, int y, int id, char t);


};

#endif // PORTAAVIONES_H
