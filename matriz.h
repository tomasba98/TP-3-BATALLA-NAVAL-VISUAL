#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"
#include <vector>
#include <iostream>

class Matriz
{
private:
    char **matriz;
    int tamanioMatriz = 11;
    int numBarcos;
    bool hit;
    char submarinoHitChar = 'K';
    int infodisparo=0;

    std::vector <Barco> cantBarcos;

public:
    Matriz();

    void crear_matriz();
    void agregar_barco(Barco *barco);
    bool lugarDisponible(int, int, int, char);
    void disparar(int, int);
    void moverLancha();
    void eliminarBarco(Barco b);
    bool matrizHit();
    void modificarMatriz(int,int,char);    
    char submarinoHit();
    bool lugarLancha(int, int, int, char);

    int getTamanioMatriz() const;
    int getNumBarcos() const;
    int getInfodisparo() const;
    char** getMatriz();
    std::vector<Barco> &getCantBarcos();


    void setTamanioMatriz(int newTamanioMatriz);
    void setNumBarcos(int newNumBarcos);
    void setMatriz(char **newMatriz);
    void setInfodisparo(int newInfodisparo);
    void setCantBarcos(const std::vector<Barco> &newCantBarcos);
};

#endif // MATRIZ_H
