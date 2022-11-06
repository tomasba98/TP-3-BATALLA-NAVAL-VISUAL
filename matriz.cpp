#include "matriz.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

void Matriz::setMatriz(char **newMatriz)
{
    matriz = newMatriz;
}

int Matriz::getInfodisparo() const
{
    return infodisparo;
}

void Matriz::setInfodisparo(int newInfodisparo)
{
    infodisparo = newInfodisparo;
}

std::vector<Barco*> &Matriz::getCantBarcos()
{
    return cantBarcos;
}

void Matriz::setCantBarcos(const std::vector<Barco*> &newCantBarcos)
{
    cantBarcos = newCantBarcos;
}

void Matriz::actualizar()
{

    for(int i=0;i<this->tamanioMatriz;i++){
        for(int j=0;j<this->tamanioMatriz;j++){
            this->matriz[i][j]= '~';
        }

    }

    for(auto it : this->disparos){

        this->disparar(it.second,it.first);

//        if(this->matriz[it.second][it.first] == '~'){
//            this->matriz[it.second][it.first] = 'o';
//        }else{
//            this->matriz[it.second][it.first] = 'x';
//        }

    }

    for(auto it : this->cantBarcos){
        switch(it->getOrientacion()){
        case 'H':{

            for(int i=0 ; i<it->getTamanio() ; i++){
                this->matriz[it->getY()][it->getX()+i] = it->getNum();
            }

            break;
        }
        case 'V':{

            for(int i=0 ; i<it->getTamanio() ; i++){
                this->matriz[it->getY()+i][it->getX()] = it->getNum();
            }

            break;
        }

        }
    }
}

std::vector<std::pair<int, int> > &Matriz::getDisparos()
{
    return disparos;
}

void Matriz::setDisparos(const std::vector<std::pair<int, int> > &newDisparos)
{
    disparos = newDisparos;
}

Matriz::Matriz()
{
    this->numBarcos=0;
}

int Matriz::getNumBarcos() const
{
    return numBarcos;
}

void Matriz::setNumBarcos(int newNumBarcos)
{
    numBarcos = newNumBarcos;
}

bool Matriz::matrizHit()
{
    return this->hit;
}

void Matriz::modificarMatriz(int x, int y, char c)
{
    this->matriz[y][x]= c;
}
void Matriz::mostrarFlota()
{
    //    std::cout<<"\n   Barcos en flota: \n";
    //    for (Barco b : this->cantBarcos){
    //        std::cout<<std::setw(12)<<b.getNombre()<<"  -> "<<std::setw(7)<<"Life: "<<b.getVida()<<"/"<<b.getTamanio()<<std::endl;
    //    }
}


char Matriz::submarinoHit()
{
    return this->submarinoHitChar;
}



int Matriz::getTamanioMatriz() const
{
    return tamanioMatriz;
}

void Matriz::setTamanioMatriz(int newTamanioMatriz)
{
    tamanioMatriz = newTamanioMatriz;
}

bool Matriz::lugarDisponible(int posX, int posY, int tamanio, char orientacion)
{
    int tamanioMatr = this->getTamanioMatriz();
    int tamanioX = posX+tamanio;
    int tamanioY = posY+tamanio;


    if(((posX>0) && (posX<tamanioMatr-1)) && ((posY>0) && (posY<tamanioMatr-1))){
        switch(orientacion){
        case 'H':
            if(tamanioX<tamanioMatr){
                if(matriz[posY][posX-1] == '~' && matriz[posY][tamanioX] == '~'){
                    for (int i=0;i<tamanio;i++){
                        if(matriz[posY][posX+i] != '~'){
                            return false;
                        }
                    }
                    for (int i=0;i<tamanio;i++){
                        if((matriz[posY-1][posX+i] != '~')||(matriz[posY+1][posX+i] != '~')){
                            return false;
                        }
                    }
                }else{
                    return false;
                }
                return true;
            }else{
                return false;
            }
            break;
        case 'V':
            if(tamanioY<tamanioMatr){
                if(matriz[posY-1][posX] == '~' && matriz[tamanioY][posX] == '~'){
                    for (int i=0;i<tamanio;i++){
                        if(matriz[posY+i][posX] != '~'){
                            return false;
                        }
                        for (int i=0;i<tamanio;i++){
                            if((matriz[posY+i][posX-1] != '~')||(matriz[posY+i][posX+1] != '~')){
                                return false;
                            }
                        }
                    }
                }else{
                    return false;
                }
                return true;
            }else{
                return false;
            }
            break;
        }
    }else{
        return false;
    }
    return false;
}

int Matriz::disparar(int x, int y)
{

    if((x>0 && x<this->tamanioMatriz) && (y>0 && y<this->tamanioMatriz)){
        char caract = this->matriz[y][x];

        switch(caract){
        case '~':
            this->matriz[y][x] = 'O';

            this->hit = false;
            this->infodisparo = 0;

            this->submarinoHitChar = 'K';
            break;
        case '1':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (auto b : this->cantBarcos){
                if(b->getNum()=='1'){
                    if(x==b->getX() && y==b->getY()){

                        this->infodisparo = 1;
                        b->hit();

                        if(b->explotado()){
                            this->infodisparo = -1;
                            this->eliminarBarco(b);
                        }
                    }

                }
            }

            break;
        case '3':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (auto b : this->cantBarcos){
                if(b->getNum()=='3'){
                    if(b->getOrientacion()=='H'){
                        int BarcoY = b->getY();
                        if(BarcoY==y){
                            int BarcoX = b->getX();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoX==x){

                                    this->infodisparo = 1;
                                    b->hit();

                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoX +=1;
                            }
                        }

                    }
                    if(b->getOrientacion()=='V'){
                        int BarcoX = b->getX();
                        if(BarcoX==x){
                            int BarcoY = b->getY();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoY==y){

                                    this->infodisparo = 1;
                                    b->hit();

                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoY +=1;
                            }

                        }
                    }
                }
            }

            break;
        case '4':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (auto b : this->cantBarcos){
                if(b->getNum()=='4'){
                    if(b->getOrientacion()=='H'){
                        int BarcoY = b->getY();
                        if(BarcoY==y){
                            int BarcoX = b->getX();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoX==x){

                                    this->infodisparo = 1;
                                    b->hit();

                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoX +=1;
                            }
                        }

                    }
                    if(b->getOrientacion()=='V'){
                        int BarcoX = b->getX();
                        if(BarcoX==x){
                            int BarcoY = b->getY();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoY==y){

                                    this->infodisparo = 1;
                                    b->hit();

                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoY +=1;
                            }

                        }
                    }
                }
            }

            break;
        case '5':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (auto b : this->cantBarcos){
                if(b->getNum()=='5'){
                    if(b->getOrientacion()=='H'){
                        int BarcoY = b->getY();
                        if(BarcoY==y){
                            int BarcoX = b->getX();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoX==x){

                                    this->infodisparo = 1;
                                    b->hit();

                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoX +=1;
                            }
                        }

                    }
                    if(b->getOrientacion()=='V'){
                        int BarcoX = b->getX();
                        if(BarcoX==x){
                            int BarcoY = b->getY();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoY==y){
                                    this->infodisparo = 1;
                                    b->hit();
                                    if(b->explotado()){
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }
                                }
                                BarcoY +=1;
                            }

                        }
                    }
                }
            }

            break;
        case '7':
            this->hit = true;
            for (auto b : this->cantBarcos){
                if(b->getNum()=='7'){
                    if(b->getOrientacion()=='H'){
                        int BarcoY = b->getY();
                        if(BarcoY==y){
                            int BarcoX = b->getX();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoX==x){
                                    if(this->matriz[y][x-1]=='7'&&this->matriz[y][x+1]=='7'){
                                        this->submarinoHitChar = 'H';
                                        b->setVida(0);
                                        b->hit();
                                        this->matriz[y][x]='X';
                                        this->matriz[y][x-1]='X';
                                        this->matriz[y][x+1]='X';
                                        b->explotado();

                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }else{
                                        this->infodisparo = 1;
                                        b->hit();
                                        if(b->explotado()){
                                            this->infodisparo = -1;
                                            this->eliminarBarco(b);
                                        }
                                        this->matriz[y][x] = 'X';
                                    }
                                }
                                BarcoX +=1;
                            }
                        }
                    }

                    if(b->getOrientacion()=='V'){
                        int BarcoX = b->getX();
                        if(BarcoX==x){
                            int BarcoY = b->getY();
                            int tamanio =b->getTamanio();
                            for (int i=0;i<=tamanio;i++){
                                if(BarcoY==y){
                                    if(this->matriz[y-1][x]=='7'&&this->matriz[y+1][x]=='7'){
                                        this->submarinoHitChar = 'V';
                                        b->setVida(0);
                                        b->hit();
                                        this->matriz[y][x]='X';
                                        this->matriz[y-1][x]='X';
                                        this->matriz[y+1][x]='X';
                                        b->explotado();
                                        this->infodisparo = -1;
                                        this->eliminarBarco(b);
                                    }else{
                                        this->infodisparo = 1;
                                        b->hit();
                                        if(b->explotado()){
                                            this->infodisparo = -1;
                                            this->eliminarBarco(b);
                                        }
                                        this->matriz[y][x] = 'X';
                                    }

                                }
                                BarcoY +=1;
                            }
                        }

                    }
                }

            }

            break;
        }

    }
    this->moverLancha();
    this->actualizar();
}

bool Matriz::lugarLancha(int posX, int posY, int tamanio, char orientacion)
{

    int tamanioMatr = this->getTamanioMatriz();
    int tamanioX = posX+tamanio;
    int tamanioY = posY+tamanio;

    if(((posX>0) && (posX<tamanioMatr)) && ((posY>0) && (posY<tamanioMatr))){
        switch(orientacion){
        case 'H':
            if(tamanioX<=tamanioMatr){
                for (int i=0;i<tamanio;i++){
                    if((matriz[posY][posX+i] != '~')){
                        return false;
                    }
                }
            }else{
                return false;
            }

            return true;
            break;
        case 'V':
            if(tamanioY<=tamanioMatr){
                for (int i=0;i<tamanio;i++){
                    if((matriz[posY+i][posX] != '~')){
                        return false;
                    }
                }
            }else{
                return false;
            }
            return true;
            break;
        }
    }else{
        return false;
    }
    return true;
}

char **Matriz::getMatriz()
{
    return this->matriz;
}

void Matriz::moverLancha()
{
    for (Barco*& b : this->cantBarcos){


        //        if(b->getTamanio()==1){
        //            bool sePudo = false;
        //            while(!sePudo){
        //                int i =rand()%this->tamanioMatriz;
        //                int j =rand()%this->tamanioMatriz;

        //                if(this->lugarLancha(i, j, b->getTamanio(), 'V')){
        //                    this->matriz[b->getY()][b->getX()]= '~';
        //                    b->setX(i);
        //                    b->setY(j);
        //                    b->setOrientacion('V');
        //                    this->matriz[b->getY()][b->getX()]= '1';
        //                    sePudo = true;
        //                }
        //            }
        //    }

        //    }
        {

            if(b->getTamanio()==1){
                bool sePudo = false;
                while(!sePudo){

                    int posMovimiento = rand()%(4);

                    switch(posMovimiento){
                    case 0:
                        //ARRIBA
                        if(this->lugarLancha(b->getX(), b->getY()-1, b->getTamanio(), 'V')){
                            this->matriz[b->getY()][b->getX()]= '~';
                            b->setY(b->getY()-1);
                            b->setOrientacion('V');
                            this->matriz[b->getY()][b->getX()]= '1';
                            sePudo = true;
                        }
                        break;
                    case 1:
                        //ABAJO
                        if(this->lugarLancha(b->getX(), b->getY()+1, b->getTamanio(), 'V')){
                            this->matriz[b->getY()][b->getX()]= '~';
                            b->setY(b->getY()+1);
                            b->setOrientacion('V');
                            this->matriz[b->getY()][b->getX()]= '1';
                            sePudo = true;
                        }
                        break;
                    case 2:
                        //IZQUIERDA
                        if(this->lugarLancha(b->getX()-1, b->getY(), b->getTamanio(), 'H')){
                            this->matriz[b->getY()][b->getX()]= '~';
                            b->setX(b->getX()-1);
                            b->setOrientacion('H');
                            this->matriz[b->getY()][b->getX()]= '1';
                            sePudo = true;
                        }
                        break;
                    case 3:
                        //DERECHA
                        if(this->lugarLancha(b->getX()+1, b->getY(), b->getTamanio(), 'H')){
                            this->matriz[b->getY()][b->getX()]= '~';
                            b->setX(b->getX()+1);
                            b->setOrientacion('H');
                            this->matriz[b->getY()][b->getX()]= '1';
                            sePudo = true;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Matriz::eliminarBarco(Barco* b)
{   std::vector <Barco*> aux;

    for (auto a : this->cantBarcos){
        if(a->getId()!=b->getId()){
            aux.push_back(a);
        }
    }
    this->cantBarcos = aux;
    //aux.end();
    this->numBarcos--;
}




void Matriz::crear_matriz(){
    //CREAR MATRIZ
    this->matriz= new char*[this->tamanioMatriz];
    for(int i=0;i<this->tamanioMatriz;i++){
        this->matriz[i]=new char[this->tamanioMatriz];
    }

    for(int i=0;i<this->tamanioMatriz;i++){
        for(int j=0;j<this->tamanioMatriz;j++){
            this->matriz[i][j]= '~';
        }

    }

}

void Matriz::agregar_barco(Barco *barco)
{
    int tamanio = barco->getTamanio();
    char orientacion = barco->getOrientacion();
    int x = barco->getX();
    int y = barco->getY();
    int id = rand()%50000;
    barco->setId(id);

    switch(orientacion){
    case 'H':
        //posicion X HORIZONAL
        for (int i=0;i<tamanio;i++){
            this->matriz[y][i+x] = barco->getNum();
        }
        break;
    case 'V':
        //posicion Y VERTICAL
        for (int i=0;i<tamanio;i++){
            this->matriz[i+y][x] = barco->getNum();
        }
        break;
    }

    this->cantBarcos.push_back(barco);
    this->numBarcos++;
}


