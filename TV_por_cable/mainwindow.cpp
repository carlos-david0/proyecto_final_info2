#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene;
    escena->setSceneRect(0, 0, ui->graphicsView->width()-5, ui->graphicsView->height()-5);
    escena->setBackgroundBrush(QColor(251, 151, 80));
    ui->graphicsView->setScene(escena);
    menu(true);
    for (short int i = 0; i < 10; i++){
        coleccionables[i] = new coleccionable;
    }
    connect(ui->jugar,SIGNAL(clicked(bool)),this,SLOT(jugar_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete imagen;
}

void MainWindow::menu(bool value)
{
    ui->jugar->setVisible(value);
    ui->jugar->setEnabled(value);
    if (value){
        QPalette pal = ui->jugar->palette();
        pal.setColor(QPalette::Button, QColor(Qt::yellow));
        ui->jugar->setAutoFillBackground(true);
        ui->jugar->setPalette(pal);
        imagen = new imagenes;
        imagen->setPos(ui->graphicsView->width()/4+10, ui->graphicsView->height()/8);
        escena->addItem(imagen);
    }
    if(!value){
        imagen->setVisible(value);
    }
}

void MainWindow::min_canasta()
{
    // representacion: c
    j1->setimage('c');
    j1->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height()-100);
    for (short int i = 0; i < 10; i++){
        coleccionables[i]->actualizador('d', puntuacion, 'c');
    }
}

void MainWindow::jugar_clicked()
{
    menu(false);
    j1 = new player;
    escena->addItem(j1);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_W:
        j1->setdireccion('w');
        break;
    case Qt::Key_A:
        j1->setdireccion('a');
        break;
    case Qt::Key_D:
        j1->setdireccion('d');
        break;
    case Qt::Key_S:
        j1->setdireccion('s');
        break;
    default:
        break;
    }
}

void MainWindow::step()
{
    for (short int i = 0; i < 10; ++i) {
        coleccionables[i] ->setPos(coleccionables[i]->x()+coleccionables[i]->get_velx(), coleccionables[i]->y()+coleccionables[i]->get_vely());
    }
}
