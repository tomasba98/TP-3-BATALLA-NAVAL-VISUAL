#ifndef JUGAR_H
#define JUGAR_H
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"
#include "submarino.h"
#include <stdlib.h>
#include <vector>


class Jugar
{
protected:



public:
    bool gameOver;
    Matriz tablero1;    //user
    Matriz tablero2;    //ia
    Matriz tableroParaDisparar;    //user
    std::vector <Barco*> Barcos;
    int disparosIA[2];


    Jugar();
    void repetidorAleatorio();
    void agregarAleatoriosIA();
    void agregarAleatorios(Matriz &tb, Barco *barco);
    void agregarManual(Barco *barco,int,int,char);
    void dispararBot(Matriz &tb);
    void jugar();
    void crearBarcos(int );
    void copiarTableroParaDisparar(Matriz &,int , int );
    void cleanWindows();
    void SeleccionarParametrosInicio(int,int);
    const std::vector<Barco *> &getBarcos() const;
    const Matriz &getTablero1() const;
    void setTablero1(const Matriz &newTablero1);
    void setDisparosIa(int x, int y);
    int* getDisparosIa();
};

#endif // JUGAR_H
