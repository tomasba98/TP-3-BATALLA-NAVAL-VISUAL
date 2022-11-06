#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "jugar.h"
#include <QMessageBox>
#include "QAction"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int,QWidget *parent = nullptr);
    MainWindow(int,int,bool,QWidget *parent = nullptr);
    ~MainWindow();

    void crearMapa();
    void actualizarMapa();
    void infoHits(int);
    void mostrarFlota();
    void gameOver();

    int getTamMapa() const;
    int getCantBarcos() const;
    bool getAleatorios() const;

    void setTamMapa(int newTamMapa);
    void setCantBarcos(int newCantBarcos);
    void setAleatorios(bool newAleatorios);

protected:
    QLabel *** tablero1;
    QLabel *** tableroIA;
    Jugar Juego;
    int contBarcos = 0;

    Ui::MainWindow *ui;
    int infoDisparo = 0;
    int tamMapa;
    int cantBarcos;
    bool aleatorios = true;
    bool gameover = false;

private slots:
    void on_agregarButton_clicked();
    void on_dispararButton_clicked();
    void on_actionGuardar_triggered();
};
#endif // MAINWINDOW_H
