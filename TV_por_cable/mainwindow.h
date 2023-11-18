#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "imagenes.h"
#include "player.h"
#include "coleccionable.h"

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
    void min_canasta();

public slots:
    void jugar_clicked();
    void keyPressEvent(QKeyEvent *event);
    void step();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    imagenes *imagen;
    player *j1;
    coleccionable *coleccionables[10];
    QTimer *tiempo;
    int puntuacion;
};
#endif // MAINWINDOW_H
