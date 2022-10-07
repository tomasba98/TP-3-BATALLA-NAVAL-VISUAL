#include "menu.h"
#include <iomanip>

using namespace std;

Menu::Menu()
{
    gameOver = false;

}

void Menu::SeleccionarParametrosInicio(Matriz &tablero1, Matriz &tablero2, Matriz &tableroParaDisparar)
{
    int cant;
    int tamañoMatriz;
    cout<<"-OJO! EL TAMANIO DE LA MATRIZ DEBE SER EL DOBLE DE CANTIDAD DE BARCOS"<<endl;
    cout<<"\nElija cantidad de Barcos: ";
    cin>>cant;
    cout<<"Elija tamanio del tablero: ";
    cin>>tamañoMatriz;
    tablero1.setTamanioMatriz(tamañoMatriz);
    tablero2.setTamanioMatriz(tamañoMatriz);
    tableroParaDisparar.setTamanioMatriz(tamañoMatriz);

    tablero1.crear_matriz();
    tablero2.crear_matriz();
    tableroParaDisparar.crear_matriz();

    cout<<"\nDIVIERTASE O MUERA!!!\n"<<endl;

    this->crearBarcos(cant);
}

void Menu::jugar()
{
    while(!gameOver){
        cout<<"--------BATALLA NAVAL MALVINAS-----------\n";

        SeleccionarParametrosInicio(tablero1, tablero2, tableroParaDisparar);

        char respuestaAleatorio;
        cout<<"Desea agregar aleatoriamente los barcos? (S/N): ";
        cin>>respuestaAleatorio;

        if(respuestaAleatorio == 'S' || respuestaAleatorio == 's'){
            for(Barco *b : this->Barcos){
                agregarAleatorios(this->tablero1,b);
                agregarAleatorios(this->tablero2,b);
            }


        }else if(respuestaAleatorio == 'N' || respuestaAleatorio == 'n'){
            for(Barco *b : this->Barcos){
                cout<<"\n          TABLERO USER"<<endl;
                tablero1.mostrar_matriz();
                agregarManual(this->tablero1,b);
                agregarAleatorios(this->tablero2,b);
                this->cleanWindows();
            }
        }


        int x,y = 99999;

       while(tablero1.getNumBarcos()!=0 && tablero2.getNumBarcos()!=0){
            this->cleanWindows();

            cout<<"--------BATALLA NAVAL MALVINAS-----------\n";
            if(y!=99999){
                cout<<"DISPARO USER:";
                this->tablero2.disparar(x,y);
                cout<<"\nDISPARO IA:";
                this->dispararBot(this->tablero1);
                cout<<endl;
                this->copiarTableroParaDisparar(tablero2,x,y);                
            }
            cout<<"          MONITOR SHOTS"<<endl;
            this->tableroParaDisparar.mostrar_matriz();
            cout<<endl;
            cout<<"          TABLERO USER"<<endl;
            tablero1.mostrar_matriz();
            tablero1.mostrarFlota();
            cout<<endl;

//            cout<<"          TABLERO IA"<<endl;
//            tablero2.mostrar_matriz();
//            tablero2.mostrarFlota();
//            cout<<endl;

            cout<<"DISPARE"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;

        }



        if(tablero1.getNumBarcos()==0 && tablero2.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nEMPATE!!\nLOS 2 SON MUY BUENOS!!!\n.";
        }

        if(tablero1.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nGAME OVER!!\nGANO IA!!!\n.";
        }
        if(tablero2.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nWIN!!\nGANASTE PAPA!!!\n.";
        }


        system("pause");
    }
}

void Menu::agregarAleatorios(Matriz &tb, Barco *barco)
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

void Menu::agregarManual(Matriz &tb, Barco *barco)
{
    int x,y;
    char orientacion;
    cout<<"\nIngrese posiciones para el barco '"<<barco->getNombre()<<"' \nTamanio: "<<barco->getTamanio()<<endl;
    cout<<"posicion x: ";cin>>x;
    cout<<"posicion y: ";cin>>y;
    cout<<"orientacion H/V: ";cin>>orientacion;

    if(orientacion=='v')
        orientacion='V';
    if(orientacion=='h')
        orientacion='H';

    while(!tb.lugarDisponible(x,y,barco->getTamanio(),orientacion)){
        cout<<"\n\nNO SE PUEDE ESA POSICION"<<endl;
        cout<<"\nIngrese nuevas posiciones para el barco "<<barco->getNombre()<<" \nTamanio: "<<barco->getTamanio()<<endl;
        cout<<"posicion x: ";cin>>x;
        cout<<"posicion y: ";cin>>y;
        cout<<"orientacion H/V: ";cin>>orientacion;
    }
    barco->setX(x);
    barco->setY(y);
    barco->setOrientacion(orientacion);
    tb.agregar_barco(barco);

}

void Menu::dispararBot(Matriz &tb)
{
    int x = rand()%9+1;
    int y = rand()%9+1;

    tb.disparar(x,y);

}

void Menu::crearBarcos(int cant)
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

void Menu::copiarTableroParaDisparar(Matriz &tb2,int x, int y)
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

void Menu::cleanWindows()
{
#ifdef _WIN32
    std::system("cls");
#elif __unix__
    std::system("clear");
#endif
}
