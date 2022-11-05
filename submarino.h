#ifndef SUBMARINO_H
#define SUBMARINO_H
#include "barco.h"

class Submarino : public Barco
{
public:
    Submarino();
    Submarino(char ori, int v,int x, int y, int id, char t);


};

#endif // SUBMARINO_H
