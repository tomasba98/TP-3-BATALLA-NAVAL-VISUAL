#include "cargawindow.h"
#include "ui_cargawindow.h"
#include "fstream"

CargaWindow::CargaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CargaWindow)
{
    ui->setupUi(this);
    //ui->setTamMatr->setPlaceholderText(QStringLiteral("TAMANIO MAPA"));
    //ui->setCantBarc->setPlaceholderText(QStringLiteral("CANT BARCOS"));
}

CargaWindow::~CargaWindow()
{
    delete ui;
}

void CargaWindow::on_buttonJugar_clicked()
{
    if(this->ui->labelCantBarcos->text().isEmpty() || this->ui->labelTamMatr->text().isEmpty()){
        QMessageBox::information(this, "ALERTA", "COMPLETE LOS CAMPOS");
    } 


    int cantBarc = this->ui->setCantBarc->text().toInt();
    int tamMap = this->ui->setTamMatr->text().toInt();
    bool aleatorio = this->ui->checkBoxAleatorios->isChecked();

    this->hide();
    this->pantallaJuego = new MainWindow(cantBarc,tamMap,aleatorio);
    this->pantallaJuego->show();   

}


void CargaWindow::on_buttonCargarPartida_clicked()
{
     int tam = this->tamMatriz();
     this->hide();
     this->pantallaJuego = new MainWindow(tam);
     this->pantallaJuego->show();
}

int CargaWindow::tamMatriz()
{
    std::fstream archivo("tamMatriz.bin", std::ios::binary | std::ios::in);

    int tam = 0;

    if(archivo.is_open()){

            archivo.read((char*)&tam,sizeof(int));


        archivo.close();

    }else{
        QMessageBox::information(this, "ERROR", "CARGA MATRIZ");
    }

    return tam;
}
