#ifndef CRUCERO_H
#define CRUCERO_H
#include "barco.h"


class Crucero : public Barco
{
private:

public:
    Crucero();
    Crucero(char ori, int v,int x, int y, int id, char t);


};

#endif // CRUCERO_H
