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
     *  'b' va hacia abajo*/
    switch (tipo) {
    case 'e':{
        velx = 0;
        vely = 0;
        switch (minijuego) {
        case 'c':{
        }
            break;
        default:
            break;
        }
    }
        break;
    case 'b':{
        velx = 0;
        vely = velocidad;
        switch (minijuego) {
        case 'c':
            setPixmap(QPixmap(":/imagenes/manzana.png").scaled(30, 30));
            break;
        default:
            break;
        }
    }
    break;
    case 'd':{
        velx = (velocidad+1)/2;
        vely = 0;
        switch (minijuego) {
        case 'p':
            transition = rand()%1-1.3;
            transition = transition*10;
            vely = transition;
            setPixmap(QPixmap(":/imagenes/pelotas.png").scaled(30, 30));
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
            case 'p':{
                setPos(rand()%500-500, rand()%335+1);
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
            case 'p':{
                contacto = true;
                setPos(rand()%500-500, rand()%335+1);
            }
            break;
            default:
                break;
            }
        }
    }
    return contacto;
}

void coleccionable::controller(char minigame)
{
    switch (minigame) {
    case 'p':{
        vely += 0.3;
        if (y() >= 335){
            vely = transition;
        }
    }
        break;
    default:
        break;
    }
}
