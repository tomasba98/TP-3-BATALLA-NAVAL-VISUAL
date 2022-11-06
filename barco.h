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
    Barco();
    Barco(char ori, int v,int x, int y, int id, char t);
    int getTamanio() const ;
    void setTamanio(int );
    char getOrientacion() const ;
    void setOrientacion(char) ;
    int getVida() const;
    void setVida(int newVidas);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    char getNum() const;
    void setNum(char newNum);

    virtual void hit();
    virtual bool explotado();


    std::string &getNombre() ;
    void setNombre(const std::string &newNombre);
    int getId() const;
    void setId(int newId);
    char getTipo() const;
    void setTipo(char newTipo);
};

#endif // BARCO_H
