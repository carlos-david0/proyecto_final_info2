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
     *  'b' va hacia abajo*/
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
        case 'p':
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(30, 500));
            break;
        case 'd':
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(30, 500));
            break;
        case 'm':
            setPixmap(QPixmap(":/imagenes/barrera.png").scaled(700, 100));
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
    case 'b':{
        this->velx = (velocidad/2)+1;
        this->vely = velocidad;
        this->cuenta = rand()%100;
        switch (minijuego) {
        case 'm':
            setPixmap(QPixmap(":/imagenes/esquiadord.png").scaled(50, 50));
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
            case 'm':{
                setPos(rand()%700, rand()%500-500);
            }
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
            case 'm':{
                setPos(rand()%700, rand()%500-500);
            }
            break;
            default:
                break;
            }
        }
    }
    return colicion;
}

void obstaculo::imagen(char minijuego)
{
    switch (minijuego) {
    case 'm':{
        switch(cuenta){
            case 100:{
                velx = velx*-1;
                setPixmap(QPixmap(":/imagenes/esquiadori.png").scaled(50, 50));
                cuenta++;
            }
            break;
            case 200:{
                velx = velx*-1;
                setPixmap(QPixmap(":/imagenes/esquiadord.png").scaled(50, 50));
                cuenta = 0;
            }
            break;
            default:{
                cuenta++;
            }
            }
        }
        break;
    default:
        break;
    }
}

