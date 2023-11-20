#include "obstaculo.h"

obstaculo::obstaculo()
{

}
void obstaculo::actualizador(char tipo, int velocidad, char minijuego)
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
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(700, 30));
            break;
        case 'b':
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(30, 500));
            break;
        case 'd':
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(30, 500));
            break;
        default:
            break;
        }
    }
    break;
    case 'i':{
        this->velx = -velocidad;
        this->vely = 0;
        switch (minijuego) {
        case 'b':
            setPixmap(QPixmap(":/imagenes/bullets.png").scaled(60, 30));
            break;
        default:
            break;
        }
    }
    break;
    case 'd':{
        this->velx = velocidad;
        this->vely = 0;
        switch (minijuego) {
        case 'd':
            setPixmap(QPixmap(":/imagenes/cactus.png").scaled(60, 30));
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

short obstaculo::get_velx()
{
    return velx;
}

short obstaculo::get_vely()
{
    return vely;
}

bool obstaculo::collider(char minigame)
{
    bool colicion = false;
    QList<QGraphicsItem *> list = collidingItems();
    for (short i = 0; i < list.size(); i++){
        if (typeid(*(list[i])) == typeid(player)){
            switch (minigame) {
            case 'n':{}
            break;
            case 'b':{
                setPos(rand()%800+500, rand()%340);
            }
            break;
            case 'd':{
                setPos(0, rand()%340);
            }
            break;
            default:
                break;
            }
            colicion = true;
        }
        if (typeid(*(list[i])) == typeid(obstaculo)){
            switch (minigame) {
            case 'n':{}
            break;
            case 'b':{
                setPos(rand()%800+500, rand()%340);
            }
            break;
            case 'd':{
                setPos(0, rand()%340);
            }
            break;
            default:
                break;
            }
        }
    }
    return colicion;
}

