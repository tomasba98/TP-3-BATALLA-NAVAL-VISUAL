#ifndef LANCHA_H
#define LANCHA_H
#include "barco.h"

class Lancha : public Barco
{
public:
    Lancha();
    Lancha(char ori, int v,int x, int y, int id, char t);
};

#endif // LANCHA_H
