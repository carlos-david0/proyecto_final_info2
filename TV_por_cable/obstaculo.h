#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "player.h"

class obstaculo: public QObject, public QGraphicsPixmapItem
{
public:
    obstaculo();
    void actualizador(char tipo, int velocidad, char minijuego);
    bool collider(char minigame);
    short int get_velx();
    short int get_vely();

private:
    short int velx;
    short int vely;
};

#endif // OBSTACULO_H
