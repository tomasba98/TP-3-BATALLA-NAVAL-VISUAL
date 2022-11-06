#include "jugar.h"
#include <fstream>
#include <cstring>

using namespace std;

Jugar::Jugar()
{
}

BarcosStr asignar(Barco it){
    BarcosStr b;

    b.X = it.getX();
    b.Y = it.getY();
    strcpy_s(b.nombre,it.getNombre().c_str());
    b.num = it.getNum();
    b.orientacion = it.getOrientacion();
    b.vida = it.getVida();
    b.tamanio = it.getTamanio();
    b.id = it.getId();
    b.tipo = it.getTipo();

    return b;
}

bool Jugar:: guardarBarcos()
{
    BarcosStr b;

    string nombre = "Barcos";

    fstream archivo1("Barcos1.bin", ios::binary | ios::out | ios::trunc);
    fstream archivo2("Barcos2.bin", ios::binary | ios::out | ios::trunc);

    if(archivo1.is_open()){

        for (auto& it : this->tablero1.getCantBarcos()){

            b = asignar(it);

            archivo1.write((char*)&b,sizeof(BarcosStr));
        }

        archivo1.close();

    }else{
        return false;
    }

    if(archivo2.is_open()){
        for (auto& it : this->tablero2.getCantBarcos()){

            b = asignar(it);

            archivo2.write((char*)&b,sizeof(BarcosStr));
        }

        archivo2.close();

    }else{
        return false;
    }

    return true;
}

bool Jugar::guardarDisparos()
{
    Disparos d;

    fstream archivo1("Disparos1.bin", ios::binary | ios::out | ios::trunc);
    fstream archivo2("Disparos2.bin", ios::binary | ios::out | ios::trunc);

    if(archivo1.is_open()){
        for(auto it : this->DisparosUser){
            d.x = it.first;
            d.y = it.second;
            archivo1.write((char*)&d,sizeof(Disparos));
        }

        archivo1.close();

    }else{
        return false;
    }

    if(archivo2.is_open()){
        for(auto it : this->DisparosIA){
            d.x = it.first;
            d.y = it.second;
            archivo2.write((char*)&d,sizeof(Disparos));
        }

        archivo2.close();

    }else{
        return false;
    }

    return true;
}

bool Jugar::guardarMatriz()
{
    fstream archivo("tamMatriz.bin", ios::binary | ios::out);

    int tam = this->tablero1.getTamanioMatriz();

    if(archivo.is_open()){

        archivo.write((char*)&tam,sizeof(int));


        archivo.close();
        return true;

    }else{
        return false;
    }

    return true;
}

bool Jugar::guardarJuego()
{

    if(!this->guardarBarcos()) return false;
    if(!this->guardarDisparos()) return false;
    if(this->guardarMatriz()) return false;

    return true;
}

bool Jugar::cargarBarcos()
{
    BarcosStr b;

    std::vector<Barco*> vector;

    fstream archivo1("Barcos1.bin", ios::binary | ios::in);
    fstream archivo2("Barcos2.bin", ios::binary | ios::in);

    if(archivo1.is_open()){     //char ori, int v,int x, int y, int id, char t
        while(archivo1.read((char*)&b,sizeof(BarcosStr))){
            switch(b.tipo){
            case 'c':
                vector.emplace_back(new Crucero(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'p':
                vector.emplace_back(new Portaaviones(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'd':
                vector.emplace_back(new Destructor(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'l':
                vector.emplace_back(new Lancha(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 's':
                vector.emplace_back(new Submarino(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            }
        }

        for(size_t i = 0; i<vector.size(); i++){
            this->tablero1.agregar_barco(vector[i]);
        }

        archivo1.close();
    }else{
        return false;
    }

    vector.clear();

    if(archivo2.is_open()){     //char ori, int v,int x, int y, int id, char t
        while(archivo2.read((char*)&b,sizeof(BarcosStr))){
            switch(b.tipo){
            case 'c':
                vector.emplace_back(new Crucero(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'p':
                vector.emplace_back(new Portaaviones(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'd':
                vector.emplace_back(new Destructor(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 'l':
                vector.emplace_back(new Lancha(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            case 's':
                vector.emplace_back(new Submarino(b.orientacion,b.vida,b.X,b.Y,b.id,b.tipo));
                break;
            }
        }

        for(size_t i = 0; i<vector.size(); i++){
            this->tablero2.agregar_barco(vector[i]);
        }

        archivo2.close();
    }else{
        return false;
    }

    return true;
}

bool Jugar::cargarDisparos(Matriz &tb )
{
    Disparos dis;

    fstream archivo1("Disparos1.bin", ios::binary | ios::in );
    fstream archivo2("Disparos2.bin", ios::binary | ios::in );


    if(archivo1.is_open()){

        while(archivo1.read((char*)&dis,sizeof(Disparos))){
            this->dispararUser(dis.x,dis.y);
        }
        archivo1.close();

    }else{
        return false;
    }

    if(archivo2.is_open()){

        while(archivo2.read((char*)&dis,sizeof(Disparos))){
            tb.disparar(dis.x,dis.y);
            this->DisparosIA.push_back({dis.x,dis.y});
        }
        archivo2.close();
    }else{
        return false;
    }

    return true;
}

void Jugar::cargarMapa(int tam)
{
    this->tablero1.setTamanioMatriz(tam);
    this->tablero2.setTamanioMatriz(tam);
    this->tableroParaDisparar.setTamanioMatriz(tam);
    this->tablero1.crear_matriz();
    this->tablero2.crear_matriz();
    this->tableroParaDisparar.crear_matriz();
}

bool Jugar::cargarJuego(Matriz &tb,int t)
{
    this->cargarMapa(t);
    if(!this->cargarBarcos()) return false;
    if(!this->cargarDisparos(tb)) return false;

    return true;
}

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

void Jugar::dispararUser(int x, int y)
{
    this->DisparosUser.push_back({x,y});

    this->tablero2.disparar(x, y);
    this->copiarTableroParaDisparar(this->tablero2,x,y);
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
    for(auto b : this->Barcos){
        agregarAleatorios(this->tablero1,b);
    }
}

void Jugar::agregarAleatoriosIA()
{
    for(auto b : this->Barcos){
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
    int tm = tb.getTamanioMatriz();

    int x = rand()%tm+1;
    int y = rand()%tm+1;

    this->DisparosIA.push_back({x,y});

    tb.disparar(x,y);
}

void Jugar::crearBarcos(int cant)
{
    int tipo = 0;

    for(int i=0;i<cant;i++){
        tipo = rand()% 4;
        switch(tipo){
        case 0:{
            Barco *crucero = new Crucero;
            crucero->setTipo('c');
            this->Barcos.push_back(crucero);
            break;
        }
        case 1:{
            Barco *portaaviones = new Portaaviones;
            portaaviones->setTipo('p');
            this->Barcos.push_back(portaaviones);
            break;
        }
        case 2:{Barco *destructor = new Destructor;
            destructor->setTipo('d');
            this->Barcos.push_back(destructor);
            break;
        }
        case 3:{
            Barco *submarino = new Submarino;
            submarino->setTipo('s');
            this->Barcos.push_back(submarino);
            break;
        }
        case 4:{
            Barco *lancha = new Lancha;
            lancha->setTipo('l');
            this->Barcos.push_back(lancha);
        }
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
