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

struct BarcosStr{
    char nombre[30];
    char num;
    int tamanio;
    char orientacion;
    int vida;
    int X;
    int Y;
    int id;
    char tipo;
};typedef struct BarcosStr BarcosStr;

struct disparos
{
    int x;
    int y;
};typedef struct disparos Disparos;

class Jugar
{
protected:



public:
    int tamanioMat;
    bool gameOver;
    Matriz tablero1;    //user
    Matriz tablero2;    //ia
    Matriz tableroParaDisparar;    //user
    std::vector <Barco*> Barcos;
    std::vector <std::pair<int,int>> DisparosUser;
    std::vector <std::pair<int,int>> DisparosIA;


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
    void dispararUser(int,int);

    bool guardarBarcos();
    bool guardarDisparos();
    bool guardarJuego();
    void cargarJuego();
};

#endif // JUGAR_H
