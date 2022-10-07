#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( int Cbarcos,int Tmap, bool alea,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->tamMapa = Tmap;
    this->cantBarcos = Cbarcos;
    this->aleatorios = alea;

    this->aleatorios?this->ui->cargaManualContainer->hide():this->ui->cargaManualContainer->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getTamMapa() const
{
    return tamMapa;
}

void MainWindow::setTamMapa(int newTamMapa)
{
    tamMapa = newTamMapa;
}

int MainWindow::getCantBarcos() const
{
    return cantBarcos;
}

void MainWindow::setCantBarcos(int newCantBarcos)
{
    cantBarcos = newCantBarcos;
}

bool MainWindow::getAleatorios() const
{
    return aleatorios;
}

void MainWindow::setAleatorios(bool newAleatorios)
{
    aleatorios = newAleatorios;
}

