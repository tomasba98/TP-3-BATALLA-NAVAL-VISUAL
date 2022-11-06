#ifndef JUGAR_H
#define JUGAR_H
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"
#include "qtmetamacros.h"
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

public:
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
    void crearBarcos(int);
    void copiarTableroParaDisparar(Matriz &,int , int );
    void cleanWindows();
    void SeleccionarParametrosInicio(int,int);
    void dispararUser(int,int);
    bool guardarJuego();
    bool cargarJuego(Matriz &tb,int);

    void setDisparosIa(int x, int y);
    void setTablero1(const Matriz &newTablero1);

    int* getDisparosIa();
    const std::vector<Barco *> &getBarcos() const;
    const Matriz &getTablero1() const;

private slots:
    bool guardarBarcos();
    bool guardarDisparos();
    bool guardarMatriz();

    bool cargarBarcos();
    bool cargarDisparos(Matriz &tb);
    void cargarMapa(int tam);

};

#endif // JUGAR_H
