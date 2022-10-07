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
    std::vector <Barco> cantBarcos;
    bool hit;
    char submarinoHitChar = 'K';

public:
    Matriz();

    void chequearVector();
    void crear_matriz();
    void mostrar_matriz();
    void agregar_barco(Barco *barco);
    int getTamanioMatriz() const;
    void setTamanioMatriz(int newTamanioMatriz);
    bool lugarDisponible(int, int, int, char);
    int disparar(int, int);
    void moverLancha();
    void eliminarBarco(Barco b);
    int getNumBarcos() const;
    void setNumBarcos(int newNumBarcos);
    bool matrizHit();
    void modificarMatriz(int,int,char);
    void mostrarFlota();
    char submarinoHit();
    bool lugarLancha(int, int, int, char);
};

#endif // MATRIZ_H
