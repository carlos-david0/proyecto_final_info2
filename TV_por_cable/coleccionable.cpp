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

            break;
        default:
            break;
        }
    }
        break;
    case 'd':{
        this->velx = 0;
        this->vely = velocidad;
        switch (minijuego) {
        case 'c':
            setPixmap(QPixmap(":/imagenes/manzana.png").scaled(30, 30));
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

short coleccionable::get_velx()
{
    return velx;
}

short coleccionable::get_vely()
{
    return vely;
}

bool coleccionable::collider(char minigame)
{
    bool contacto = false;
    QList<QGraphicsItem *> list = collidingItems();
    for (short i = 0; i < list.size(); i++){
        if (typeid(*(list[i])) == typeid(player)){
            switch (minigame) {
            case 'n':{}
                break;
            case 'c':{
                setPos(rand()%241+320, rand()%1000-1000);
            }
            break;
            default:
                break;
            }
        }
        if (typeid(*(list[i])) == typeid(obstaculo)){
            switch (minigame) {
            case 'n':{}
            break;
            case 'c':{
                contacto = true;
                setPos(rand()%241+320, rand()%1000-1000);
            }
            break;
            default:
                break;
            }
        }
    }
    return contacto;
}
