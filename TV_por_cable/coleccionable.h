#ifndef COLECCIONABLE_H
#define COLECCIONABLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class coleccionable: public QObject, public QGraphicsPixmapItem
{
public:
    coleccionable();
    void actualizador(char tipo, int velocidad, char minijuego);
    unsigned short int get_velx();
    unsigned short int get_vely();

private:
    unsigned short int velx;
    unsigned short int vely;
};

#endif // COLECCIONABLE_H
