#include "jugar.h"

using namespace std;

const std::vector<Barco *> &Jugar::getBarcos() const
{
    return Barcos;
}

const Matriz &Jugar::getTablero1() const
{
    return tablero1;
}

void Jugar::setTablero1(const Matriz &newTablero1)
{
    tablero1 = newTablero1;
}

void Jugar::setDisparosIa(int x, int y)
{
    this->disparosIA[0] = x;
    this->disparosIA[1] = y;
}

int *Jugar::getDisparosIa()
{
    return disparosIA;
}



Jugar::Jugar()
{
    gameOver = false;
}

void Jugar::SeleccionarParametrosInicio(int cant,int tamanioMatriz)
{

    this->tablero1.setTamanioMatriz(tamanioMatriz);
    this->tablero2.setTamanioMatriz(tamanioMatriz);
    this->tableroParaDisparar.setTamanioMatriz(tamanioMatriz);
    this->tablero1.crear_matriz();
    this->tablero2.crear_matriz();
    this->tableroParaDisparar.crear_matriz();

    this->crearBarcos(cant);
    this->agregarAleatoriosIA();
}



void Jugar::repetidorAleatorio()
{
    for(Barco *b : this->Barcos){
        agregarAleatorios(this->tablero1,b);
    }
}

void Jugar::agregarAleatoriosIA()
{
    for(Barco *b : this->Barcos){
        agregarAleatorios(this->tablero2,b);
    }
}

void Jugar::agregarAleatorios(Matriz &tb, Barco *barco)
{
    char orientacionChar;
    int x;
    int y;
    int orientacion;
    int tamanio = tb.getTamanioMatriz();

    do{
        x = rand()%tamanio;
        y = rand()%tamanio;
        orientacion = rand()%2;

        if(orientacion == 1){
            orientacionChar = 'V';
        }else{
            orientacionChar = 'H';
        }

    }while(!tb.lugarDisponible(x,y,barco->getTamanio(),orientacionChar));

    barco->setX(x);
    barco->setY(y);
    barco->setOrientacion(orientacionChar);
    tb.agregar_barco(barco);

}

void Jugar::agregarManual( Barco *barco,int x,int y,char orientacion)
{
    barco->setX(x);
    barco->setY(y);
    barco->setOrientacion(orientacion);
    this->tablero1.agregar_barco(barco);

}

void Jugar::dispararBot(Matriz &tb)
{
    int x = rand()%9+1;
    int y = rand()%9+1;

    this->setDisparosIa(x, y);

    tb.disparar(x,y);
}

void Jugar::crearBarcos(int cant)
{
    int tipo = 0;

    Barco *crucero = new Crucero;
    Barco *portaaviones = new Portaaviones;
    Barco *destructor = new Destructor;
    Barco *lancha = new Lancha;
    Barco *submarino = new Submarino;

    for(int i=0;i<cant;i++){
        tipo = rand()% 5;
        switch(tipo){
        case 0:
            this->Barcos.push_back(crucero);
            break;
        case 1:
            this->Barcos.push_back(portaaviones);
            break;
        case 2:
            this->Barcos.push_back(destructor);
            break;
        case 3:
            this->Barcos.push_back(lancha);
            break;
        case 4:
            this->Barcos.push_back(submarino);
            break;
        }

    }
}

void Jugar::copiarTableroParaDisparar(Matriz &tb2,int x, int y)
{
    if(tb2.matrizHit()){
        this->tableroParaDisparar.modificarMatriz(x,y,'X');
    }else{
        this->tableroParaDisparar.modificarMatriz(x,y,'O');
    }
    char orientacion = tb2.submarinoHit();
    if(orientacion=='H'){
        this->tableroParaDisparar.modificarMatriz(x-1,y,'X');
        this->tableroParaDisparar.modificarMatriz(x+1,y,'X');
    }
    if(orientacion=='V'){
        this->tableroParaDisparar.modificarMatriz(x,y-1,'X');
        this->tableroParaDisparar.modificarMatriz(x,y+1,'X');
    }
}
