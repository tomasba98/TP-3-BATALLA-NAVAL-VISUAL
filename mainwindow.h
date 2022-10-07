#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;
    int tamMapa;
    int cantBarcos;
    bool aleatorios = true;
};
#endif // MAINWINDOW_H
