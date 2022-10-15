#include "mainwindow.h"
#include "ui_mainwindow.h"

//METODOS-----------------------

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow( int Cbarcos,int Tmap, bool alea,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->tamMapa = Tmap;
    this->cantBarcos = Cbarcos;
    this->aleatorios = alea;

    this->aleatorios?this->ui->cargaManualContainer->hide():this->ui->cargaManualContainer->show();

    this->Juego.SeleccionarParametrosInicio(Cbarcos,Tmap);

    if(this->aleatorios){
        this->Juego.repetidorAleatorio();}
    else{
        this->ui->nomBarcoLabel->setText(QString::fromStdString(this->Juego.getBarcos()[this->contBarcos]->getNombre()));
        this->ui->tamBarcoLabel_2->setText(QString::number(this->Juego.getBarcos()[this->contBarcos]->getTamanio()));
        this->cargaManual();
    }


}

void MainWindow::on_agregarButton_clicked()
{
    int x,y ,tamanio =0;
    char orientacion;

    x = this->ui->posXLineEdit->text().toInt();
    y = this->ui->posYLineEdit->text().toInt();
    orientacion = this->ui->orientacionHV->currentText().toStdString()[0];
    tamanio = this->Juego.getBarcos()[this->contBarcos]->getTamanio();


    if(this->Juego.tablero1.lugarDisponible(x,y,tamanio,orientacion)){
        if(this->contBarcos<this->cantBarcos){

            this->ui->nomBarcoLabel->setText(QString::fromStdString(this->Juego.getBarcos()[this->contBarcos]->getNombre()));
            this->ui->tamBarcoLabel_2->setText(QString::number(this->Juego.getBarcos()[this->contBarcos]->getTamanio()));
            this->Juego.agregarManual(this->Juego.getBarcos()[this->contBarcos],x,y,orientacion);
            this->contBarcos++;
            this->ui->posXLineEdit->clear();
            this->ui->posYLineEdit->clear();
        }
    }else{
        QMessageBox::information(this, "ALERTA", "LUGAR NO DISPONIBLE");
    }

}

void MainWindow::on_dispararButton_clicked()
{

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


//FUNCIONES---------------------------------------------

void MainWindow::cargaManual()
{
    //    for (auto itBarco : this->Juego.getBarcos()){

    //    }

    //    for(Barco *b :this->Juego.Barcos){
    //        this->ui->nomBarcoLabel->setText(QString::fromStdString(b->getNombre()));
    //        this->ui->tamBarcoLabel_2->setText(QString::number(b->getTamanio()));

    //    }
}



