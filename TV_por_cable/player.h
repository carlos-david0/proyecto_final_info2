#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <string>
#include "obstaculo.h"

class player: public QObject, public QGraphicsPixmapItem
{
public:
    player();
    void setdireccion(char direccion);
    void setimage(char minijuego);
    void setvidas();
    short int getvidas();
    short int get_velocidadx();
    short int get_velocidady();
    void actualizador(char minijuego, unsigned short int puntuacion);
    void reset_vidas();
private:
    char direccion;
    short int velocidadx;
    short int velocidady;
    short int vidas;
    short int skip;
};

#endif // PLAYER_H
