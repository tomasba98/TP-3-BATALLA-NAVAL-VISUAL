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

    this->crearMapa();


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
        if(this->contBarcos <this->cantBarcos){
            this->ui->nomBarcoLabel->setText(QString::fromStdString(this->Juego.getBarcos()[this->contBarcos]->getNombre()));
            this->ui->tamBarcoLabel_2->setText(QString::number(this->Juego.getBarcos()[this->contBarcos]->getTamanio()));
            this->Juego.agregarManual(this->Juego.getBarcos()[this->contBarcos],x,y,orientacion);
            this->contBarcos++;
            this->ui->posXLineEdit->clear();
            this->ui->posYLineEdit->clear();
            this->actualizarMapa();

            if(this->contBarcos == this->cantBarcos) this->ui->cargaManualContainer->hide();
        }
    }else{
        QMessageBox::information(this, "ALERTA", "LUGAR NO DISPONIBLE");
    }
}

void MainWindow::on_dispararButton_clicked()
{
    int x, y;

    x = this->ui->posXDisp->text().toInt();
    y = this->ui->posYDisp->text().toInt();

    if(this->ui->posXDisp->text().isEmpty() || this->ui->posYDisp->text().isEmpty()){
        QMessageBox::information(this, "ALERTA", "COMPLETE LOS CAMPOS");
    }else if((x>=this->tamMapa)||(y>=this->tamMapa)){
        QMessageBox::information(this, "ALERTA", "MATRIZ FUERA DE RANGO");
    }
    else{

        this->Juego.tablero2.disparar(x, y);
        this->Juego.dispararBot(this->Juego.tablero1);
        this->Juego.copiarTableroParaDisparar(this->Juego.tablero2, x, y);
        this->ui->posXDisp->clear();
        this->ui->posYDisp->clear();

        this->actualizarMapa();
    }
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

void MainWindow::crearMapa()
{
    int cantidad = this->tamMapa;


    //TABLERO USER
    this->tablero1 = new QLabel**[cantidad];
    for (int i = 0; i < cantidad; i++) {
        this->tablero1[i] = new QLabel*[cantidad];
        for (int j = 0; j < cantidad; j++) {

            this->tablero1[i][j] = new QLabel();
            this->tablero1[i][j]->setStyleSheet("font-weight: bold; text-align: center; background-color: #4682B4;");
            this->tablero1[i][j]->setAlignment(Qt::AlignCenter);//rgba(0, 141, 249, 0.3);
            this->ui->tablero1->addWidget(tablero1[i][j] ,i,j);
        }

    }

    //TABLERO IA
    this->tableroIA = new QLabel**[cantidad];
    for (int i = 0; i < cantidad; i++) {
        this->tableroIA[i] = new QLabel*[cantidad];
        for (int j = 0; j < cantidad; j++) {

            this->tableroIA[i][j] = new QLabel();
            this->tableroIA[i][j]->setStyleSheet("font-weight: bold; text-align: center; background-color: #87CEEB;");
            this->tableroIA[i][j]->setAlignment(Qt::AlignCenter);
            this->ui->tableroIA->addWidget(tableroIA[i][j] ,i,j);
        }

    }

    this->actualizarMapa();
}

void MainWindow::actualizarMapa()
{

    //TABLERO USER
    char** matriz = this->Juego.tablero1.getMatriz();
    int cantidad = this->tamMapa;
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            char c = matriz[i][j];
            QString txt((QChar(c)));
            this->tablero1[i][j]->setText(txt);
        }
    }

    //TABLERO IA
    char** matriz2 = this->Juego.tableroParaDisparar.getMatriz();

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            char x = matriz2[i][j];
            QString txt2((QChar(x)));
            this->tableroIA[i][j]->setText(txt2);
        }
    }
}
