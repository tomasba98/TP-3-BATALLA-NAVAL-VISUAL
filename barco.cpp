#include "barco.h"
#include <iostream>

Barco::Barco()
{

}

int Barco::getId() const
{
    return id;
}

void Barco::setId(int newId)
{
    id = newId;
}


const std::string &Barco::getNombre() const
{
    return nombre;
}

void Barco::setNombre(const std::string &newNombre)
{
    nombre = newNombre;
}

char Barco::getNum() const
{
    return num;
}

void Barco::setNum(char newNum)
{
    num = newNum;
}

void Barco::hit()

{
    if(this->getVida()!=0){
        this->setVida(this->getVida()-1);
    }
}

int Barco::getY() const
{
    return Y;
}

void Barco::setY(int newY)
{
    Y = newY;
}

int Barco::getX() const
{
    return X;
}

void Barco::setX(int newX)
{
    X = newX;
}


int Barco::getVida() const
{
    return vida;
}

void Barco::setVida(int newVida)
{
    vida = newVida;
}


int Barco::getTamanio() const
{
    return tamanio;
}

void Barco::setTamanio(int newTamanio)
{
    tamanio = newTamanio;
}

char Barco::getOrientacion() const
{
    return orientacion;
}

void Barco::setOrientacion(char newOrientacion)
{
    orientacion = newOrientacion;
}

bool Barco::explotado()
{
    return  this->getVida()==0;

}


