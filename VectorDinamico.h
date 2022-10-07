#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

#include <ostream>
template<class T>
class VectorDinamico
{
    private:
    T **Vector;
    int cont = 0;

    public:
    VectorDinamico(){
        this->Vector = new T* [0];
    }
    void agregarElemento(T obj){
        this->cont++;

        T **aux = new T*[cont];
        for(int i=0;i<cont-1;i++){
            aux[i]=this->Vector[i];
        }

        aux[cont-1] = &obj;
        //delete [] this->Vector;
        this->Vector= aux;
    }

    void eliminarPosicion(int pos){
        T** aux = new T*[cont-1];

        int j=0;
        for(int i=0;i<cont-1;i++){
            if(i!=pos){
                aux[i] = Vector[j];
                j++;
            }
        }
        this->Vector= aux;
    }

friend std::ostream&  operator<<(std::ostream& os, const VectorDinamico& obj)
{
    for(int i=0;i<obj.cont;i++){
        os << *obj.Vector[i];
    }
 return os;
}

};

#endif // VECTORDINAMICO_H
