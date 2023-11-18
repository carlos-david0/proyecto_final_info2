#include "coleccionable.h"

coleccionable::coleccionable()
{

}

void coleccionable::actualizador(char tipo, int velocidad, char minijuego)
{
    /* tipo:
     *  'e' estatico
     *  'i' va hacia la izquierda
     *  'd' va hacia la derecha
     *  'a' va hacia arriba
     *  'd' va hacia abajo*/
    switch (tipo) {
    case 'e':{
        this->velx = 0;
        this->vely = 0;
        switch (minijuego) {
        case 'c':
            setPixmap(QPixmap(":/imagenes/manzana.png"));
            break;
        default:
            break;
        }
    }
        break;
    case 'd':{
        this->velx = 0;
        this->vely = -velocidad;
        switch (minijuego) {
        case 'c':
            setPixmap(QPixmap(":/imagenes/manzana.png"));
            break;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
}

unsigned short coleccionable::get_velx()
{
    return velx;
}

unsigned short coleccionable::get_vely()
{
    return vely;
}
