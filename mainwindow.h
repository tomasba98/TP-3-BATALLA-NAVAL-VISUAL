#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "jugar.h"
#include "barco.h"
#include <QMessageBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int,int,bool,QWidget *parent = nullptr);
    ~MainWindow();

    int getTamMapa() const;
    void setTamMapa(int newTamMapa);

    int getCantBarcos() const;
    void setCantBarcos(int newCantBarcos);

    bool getAleatorios() const;
    void setAleatorios(bool newAleatorios);


    void cargaManual();

protected:

    Jugar Juego;
    int contBarcos = 0;

    Ui::MainWindow *ui;
    int tamMapa;
    int cantBarcos;
    bool aleatorios = true;
private slots:
    void on_agregarButton_clicked();
};
#endif // MAINWINDOW_H