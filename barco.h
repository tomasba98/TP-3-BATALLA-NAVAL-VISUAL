#ifndef BARCO_H
#define BARCO_H
#include <iostream>

class Barco
{
private:
    std::string nombre;
    char num;
    int tamanio;
    char orientacion;
    int vida;
    int X;
    int Y;
    int id;
    char tipo;

public:
    Barco(char ori, int v,int x, int y, int id, char t);
    Barco();

    int getVida() const;
    int getX() const;
    int getY() const;
    int getTamanio() const ;
    char getOrientacion() const ;
    char getNum() const;
    std::string &getNombre() ;
    int getId() const;
    char getTipo() const;

    void setTamanio(int );
    void setOrientacion(char) ;
    void setVida(int newVidas);
    void setX(int newX);
    void setY(int newY);
    void setNum(char newNum);
    void setNombre(const std::string &newNombre);
    void setId(int newId);
    void setTipo(char newTipo);

    virtual void hit();
    virtual bool explotado();
};

#endif // BARCO_H
