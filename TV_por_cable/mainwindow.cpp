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
    ui->label_2->setVisible(false);
    escena->setSceneRect(0, 0, ui->graphicsView->width()-5, ui->graphicsView->height()-5);
    ui->graphicsView->setScene(escena);
    ui->label->setVisible(false);
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
    imagen->setVisible(false);
    escena->setBackgroundBrush(QColor(251, 151, 80));
    tiempo->stop();
    cambio->stop();
    reset();
    ui->label_2->setPixmap(QPixmap(":/imagenes/0.png").scaled(30,30));
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
    escena->setBackgroundBrush(QColor(37, 228, 216));
    // representacion: c
    minijuego = 'c';
    ui->instruccion->setText("¡ATRAPA!");
    ui->instruccion->setVisible(true);
    imagen->setPos(-250, -100);
    imagen->setPixmap(QPixmap(":/imagenes/pngwing.com.png").scaled(500,500));
    imagen->setVisible(true);
    j1->actualizador(minijuego, puntuacion);
    j1->setimage(minijuego);
    j1->setVisible(true);
    j1->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height()-100);
    for (short int i = 0; i < 6; i++){
        coleccionables[i]->actualizador('b', puntuacion/2+1, minijuego);
        coleccionables[i]->setPos(rand()%241+163, rand()%1000-1000);
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
    imagen->setPos(250, 150);
    imagen->setPixmap(QPixmap(":/imagenes/nube.png").scaled(300,200));
    imagen->setVisible(true);
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
    imagen->setVisible(false);
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

void MainWindow::min_eski()
{
    escena->setBackgroundBrush(QColor(255, 255, 255));
    // representacion: m
    minijuego = 'm';
    ui->instruccion->setText("¡SOBREVIVE!");
    ui->instruccion->setVisible(true);
    imagen->setVisible(false);
    j1->actualizador(minijuego, puntuacion);
    j1->setimage(minijuego);
    j1->setVisible(true);
    j1->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height()-100);
    for (short int i = 1; i < 6; i++){
        obstaculos[i]->actualizador('b', puntuacion/2+1, minijuego);
        obstaculos[i]->setPos(rand()%600, rand()%500-500);
        obstaculos[i]->setVisible(true);
        escena->addItem(obstaculos[i]);
    }
    obstaculos[0]->actualizador('e', 0, minijuego);
    obstaculos[0]->setPos(-1, 400);
    obstaculos[0]->setVisible(true);
    escena->addItem(obstaculos[0]);
}

void MainWindow::min_pelotas(){
    escena->setBackgroundBrush(QColor(223, 181, 86));
    //representacion: p
    minijuego = 'p';
    ui->instruccion->setText("¡ANOTA!");
    ui->instruccion->setVisible(true);
    imagen->setPos(-323, 0);
    imagen->setPixmap(QPixmap(":/imagenes/cancha.png").scaled(ui->graphicsView->width()*2,ui->graphicsView->height()*2));
    imagen->setVisible(true);
    j1->actualizador(minijuego, puntuacion/2);
    j1->setVisible(true);
    j1->setPixmap(QPixmap(":/imagenes/aro.png").scaled(100, 100));
    j1->setPos((ui->graphicsView->width()/2)-52,ui->graphicsView->height()/2-50);
    obstaculos[0]->actualizador('e', 0, minijuego);
    obstaculos[0]->setPos(671,-1);
    obstaculos[0]->setVisible(true);
    escena->addItem(obstaculos[0]);
    for (short int i = 1; i < 6; i++){
        coleccionables[i]->actualizador('d', puntuacion/2+1, minijuego);
        coleccionables[i]->setPos(rand()%500-500, rand()%335+1);
        coleccionables[i]->setVisible(true);
        escena->addItem(coleccionables[i]);
    }
}

void MainWindow::jugar_clicked()
{
    menu(false);
    j1->reset_vidas();
    tiempo->start(10);
    cambio->start(10000);
    puntuacion = 1;
    ui->label->setText("Bienvenido a tu nuevo trabajo,\neres el encargado de elegir la\nprogramacion de un canal de TV.\n\nManten interesada a la audiencia\ntodo el tiempo que puedas ganando\nminijuegos.\n(WASD para moverte)");
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
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
    switch (j1->getvidas()) {
    default:
        ui->label_2->setPixmap(QPixmap(":/imagenes/0.png").scaled(30,30));
        break;
    case 1:
        ui->label_2->setPixmap(QPixmap(":/imagenes/Low.png").scaled(30,30));
        break;
    case 2:
        ui->label_2->setPixmap(QPixmap(":/imagenes/half.png").scaled(30,30));
        break;
    case 3:
        ui->label_2->setPixmap(QPixmap(":/imagenes/full.png").scaled(30,30));
        break;
    }
    for (short int i = 0; i < 6; ++i) {
        coleccionables[i] ->setPos(coleccionables[i]->x()+coleccionables[i]->get_velx(), coleccionables[i]->y()+coleccionables[i]->get_vely());
        coleccionables[i]->controller(minijuego);
        if(coleccionables[i]->collider(minijuego)){
            j1->setvidas();
        }
    }
    for (short int i = 1; i < 6; ++i) {
        obstaculos[i]->setPos(obstaculos[i]->x()+obstaculos[i]->get_velx(), obstaculos[i]->y()+obstaculos[i]->get_vely());
        obstaculos[i]->imagen(minijuego);
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
    ui->label->setVisible(false);
    reset();
    switch (rand() % 6+1) {
    case 1:
        min_canasta();
        break;
    case 2:
        min_balas();
        break;
    case 3:
        min_cactus();
        break;
    case 4:
        min_eski();
        break;
    case 5:
        min_pelotas();
        break;
    default:
        min_cactus();
        break;
    }
}
