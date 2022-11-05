#ifndef CARGAWINDOW_H
#define CARGAWINDOW_H
#include "mainwindow.h"
#include <QMessageBox>
#include <QMainWindow>

namespace Ui {
class CargaWindow;
}

class CargaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CargaWindow(QWidget *parent = nullptr);
    ~CargaWindow();

private slots:

    int tamMatriz();

    void on_buttonJugar_clicked();

    void on_buttonCargarPartida_clicked();

private:
    MainWindow *pantallaJuego = nullptr;
    Ui::CargaWindow *ui;
};

#endif // CARGAWINDOW_H
