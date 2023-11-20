#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene;
    tiempo = new QTimer;
    cambio = new QTimer;
    j1 = new player;
    escena->addItem(j1);
    minijuego = 'n';
    puntuacion = 1;
    escena->setSceneRect(0, 0, ui->graphicsView->width()-5, ui->graphicsView->height()-5);
    ui->graphicsView->setScene(escena);
    menu(true);
    for (short int i = 0; i < 6; i++){
        coleccionables[i] = new coleccionable;
        obstaculos[i] = new obstaculo;
    }
    connect(ui->jugar,SIGNAL(clicked(bool)),this,SLOT(jugar_clicked()));
    connect(tiempo,SIGNAL(timeout()),this,SLOT(step()));
    connect(cambio,SIGNAL(timeout()),this,SLOT(cambiomin()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete imagen;
    for (short int i = 0; i < 6; i++){
        delete coleccionables[i];
        delete obstaculos[i];
    }
}

void MainWindow::menu(bool value)
{
    ui->jugar->setVisible(value);
    ui->jugar->setEnabled(value);
    ui->gameover->setVisible(false);
    ui->puntuaciongo->setVisible(false);
    ui->instruccion->setVisible(false);
    if (value){
        escena->setBackgroundBrush(QColor(251, 151, 80));
        QPalette pal = ui->jugar->palette();
        pal.setColor(QPalette::Button, QColor(Qt::yellow));
        ui->jugar->setAutoFillBackground(true);
        ui->jugar->setPalette(pal);
        imagen = new imagenes;
        imagen->setPos(ui->graphicsView->width()/4+10, ui->graphicsView->height()/8);
        escena->addItem(imagen);
        ui->puntuacion->setVisible(false);
    }
    if(!value){
        imagen->setVisible(value);
        ui->puntuacion->setVisible(true);
    }
}

void MainWindow::reset()
{
    escena->setBackgroundBrush(QColor(251, 151, 80));
    ui->instruccion->setVisible(false);
    ui->puntuacion->display(puntuacion);
    j1->setVisible(false);
    for(short int i = 0; i < 6; i ++){
        coleccionables[i]->setVisible(true);
        coleccionables[i]->actualizador('e', 0, 'n');
        coleccionables[i]->setPos(-1, -1);
        if (coleccionables[i]->scene() != NULL){
            escena->removeItem(coleccionables[i]);
        }
        obstaculos[i]->setVisible(false);
        obstaculos[i]->actualizador('e', 0, 'n');
        obstaculos[i]->setPos(-1, -1);
        if (obstaculos[i]->scene() != NULL){
            escena->removeItem(obstaculos[i]);
        }
        }
    puntuacion++;
}


void MainWindow::gameover()
{
    escena->setBackgroundBrush(QColor(251, 151, 80));
    tiempo->stop();
    cambio->stop();
    reset();
    puntuacion--;
    ui->gameover->setVisible(true);
    ui->puntuacion->setVisible(false);
    ui->puntuaciongo->setVisible(true);
    ui->puntuaciongo->display(puntuacion);
    ui->jugar->setVisible(true);
    ui->jugar->setEnabled(true);
}

void MainWindow::min_canasta()
{
    escena->setBackgroundBrush(QColor(46, 135, 4));
    // representacion: c
    minijuego = 'c';
    ui->instruccion->setText("¡ATRAPA!");
    ui->instruccion->setVisible(true);
    j1->actualizador(minijuego, puntuacion);
    j1->setimage(minijuego);
    j1->setVisible(true);
    j1->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height()-100);
    for (short int i = 0; i < 6; i++){
        coleccionables[i]->actualizador('d', puntuacion/2+1, minijuego);
        coleccionables[i]->setPos(rand()%241+320, rand()%1000-1000);
        escena->addItem(coleccionables[i]);
    }
    obstaculos[0]->actualizador('e', 0, minijuego);
    obstaculos[0]->setPos(-1, 400);
    obstaculos[0]->setVisible(true);
    escena->addItem(obstaculos[0]);
}

void MainWindow::min_balas()
{
    escena->setBackgroundBrush(QColor(37, 228, 216));
    //representacion: b
    minijuego = 'b';
    ui->instruccion->setText("¡ESQUIVA!");
    ui->instruccion->setVisible(true);
    j1->actualizador(minijuego, puntuacion/2);
    j1->setVisible(true);
    j1->setPixmap(QPixmap(":/imagenes/bird1.png").scaled(100, 50));
    j1->setPos(0,ui->graphicsView->height()/2-50);
    obstaculos[0]->actualizador('e', 0, minijuego);
    obstaculos[0]->setPos(-31,-1);
    obstaculos[0]->setVisible(true);
    escena->addItem(obstaculos[0]);
    for (short int i = 1; i < 6; i++){
        obstaculos[i]->actualizador('i', puntuacion/2+1, minijuego);
        obstaculos[i]->setPos(rand()%800+500, rand()%340);
        obstaculos[i]->setVisible(true);
        escena->addItem(obstaculos[i]);
    }

}

void MainWindow::min_cactus()
{
    escena->setBackgroundBrush(QColor(238, 243, 147));
    //representacion: d
    minijuego = 'd';
    ui->instruccion->setText("¡CORRE!");
        ui->instruccion->setVisible(true);
    j1->actualizador(minijuego, puntuacion/2);
    j1->setVisible(true);
    j1->setPixmap(QPixmap(":/imagenes/Robot1.png").scaled(50, 60));
    j1->setPos(ui->graphicsView->width()/2-25,ui->graphicsView->height()/2-50);
    obstaculos[0]->actualizador('e', 0, minijuego);
    obstaculos[0]->setPos(700,-1);
    obstaculos[0]->setVisible(true);
    escena->addItem(obstaculos[0]);
    for (short int i = 1; i < 6; i++){
        obstaculos[i]->actualizador('d', puntuacion/2+1, minijuego);
        obstaculos[i]->setPos(rand()%500-500, rand()%340);
        obstaculos[i]->setVisible(true);
        escena->addItem(obstaculos[i]);
    }
}

void MainWindow::jugar_clicked()
{
    menu(false);
    j1->reset_vidas();    tiempo->start(10);
    cambio->start(10000);
    puntuacion = 1;
    //min_cactus();
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
    ui->instruccion->setVisible(false);
}

void MainWindow::step()
{

    for (short int i = 0; i < 6; ++i) {
        coleccionables[i] ->setPos(coleccionables[i]->x()+coleccionables[i]->get_velx(), coleccionables[i]->y()+coleccionables[i]->get_vely());
        if(coleccionables[i]->collider(minijuego)){
            j1->setvidas();
        }
    }
    for (short int i = 1; i < 6; ++i) {
        obstaculos[i] ->setPos(obstaculos[i]->x()+obstaculos[i]->get_velx(), obstaculos[i]->y()+obstaculos[i]->get_vely());
        if(obstaculos[i]->collider(minijuego)){
            j1->setvidas();
        }
    }
    j1->actualizador(minijuego, puntuacion/2);
    j1->setPos(j1->x()+j1->get_velocidadx(), j1->y() + j1->get_velocidady());
    j1->setimage(minijuego);
    if( j1->getvidas() <= 0){
        gameover();
    }
}

void MainWindow::cambiomin()
{
    reset();
    switch (rand() % 3+1) {
    case 1:
        min_canasta();
        break;
    case 2:
        min_balas();
        break;
    case 3:
        min_cactus();
        break;
    }
}
