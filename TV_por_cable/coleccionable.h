#ifndef COLECCIONABLE_H
#define COLECCIONABLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "obstaculo.h"

class coleccionable: public QObject, public QGraphicsPixmapItem
{
public:
    coleccionable();
    void actualizador(char tipo, int velocidad, char minijuego);
    short int get_velx();
    short int get_vely();
    bool collider(char minigame);

private:
    short int velx;
    short int vely;
};

#endif // COLECCIONABLE_H
