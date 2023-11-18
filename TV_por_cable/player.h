#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <string>

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
private:
    char direccion;
    short int velocidadx;
    short int velocidady;
    short int vidas;
};

#endif // PLAYER_H
