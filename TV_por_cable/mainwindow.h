#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <stdlib.h>
#include "imagenes.h"
#include "player.h"
#include "coleccionable.h"
#include "obstaculo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void menu(bool value);
    void reset();
    void gameover();
    void min_canasta();
    void min_balas();
    void min_cactus();
    void min_eski();
    void min_pelotas();

public slots:
    void jugar_clicked();
    void keyPressEvent(QKeyEvent *event);
    void step();
    void cambiomin();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    imagenes *imagen;
    player *j1;
    coleccionable *coleccionables[6];
    obstaculo *obstaculos[6];
    QTimer *tiempo;
    QTimer *cambio;
    int puntuacion;
    char minijuego;
};
#endif // MAINWINDOW_H
