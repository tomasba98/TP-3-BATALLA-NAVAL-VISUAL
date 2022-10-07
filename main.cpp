#include "cargawindow.h"
#include <time.h>
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    //Menu Juego;
    //Juego.jugar();

    QApplication a(argc, argv);
    CargaWindow pantallaCarga;

    pantallaCarga.show();

    return a.exec();
}
