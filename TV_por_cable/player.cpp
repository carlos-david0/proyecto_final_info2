#include "player.h"

player::player()
{
    vidas = 3;
    direccion = 'n';
    skip = 0;
}

void player::setdireccion(char direccion)
{
    this->direccion = direccion;
}

void player::setimage(char minijuego)
{
    switch (minijuego) {
    case 'c':{
        setPixmap(QPixmap(":/imagenes/canasta.png").scaled(100, 100));
    }
        break;
    case 'b':{
        switch (direccion) {
        case 'w':
            setPixmap(QPixmap(":/imagenes/bird1.png").scaled(100, 50));
            break;
        case 's':
            setPixmap(QPixmap(":/imagenes/bird2.png").scaled(100, 50));
            break;
        case 'a':
            setPixmap(QPixmap(":/imagenes/bird3.png").scaled(50, 100));
            break;
        case 'd':
            setPixmap(QPixmap(":/imagenes/bird3.png").scaled(50, 100));
            break;
        default:
            break;
        }
    }
        break;
    case 'd':{
        if (skip < 10){
        setPixmap(QPixmap(":/imagenes/Robot1.png").scaled(50, 60));
        }else if (skip < 20){
        setPixmap(QPixmap(":/imagenes/robot3.png").scaled(50, 60));
        }else if (skip < 30){
        setPixmap(QPixmap(":/imagenes/Robot1.png").scaled(50, 60));
        }else if (skip < 39){
        setPixmap(QPixmap(":/imagenes/robot2.png").scaled(50, 60));
        }else{
        skip = 0;
        }
        skip++;
    }
        break;
    default:
        break;
    }

}

void player::setvidas()
{
    vidas--;
}

short int player::getvidas()
{
    return vidas;
}

short player::get_velocidadx()
{
    return velocidadx;
}

short player::get_velocidady()
{
    return velocidady;
}

void player::actualizador(char minijuego, unsigned short puntuacion)
{
    switch (minijuego) {
    case 'c':{
        velocidady = 0;
        switch (direccion) {
        case 'a':
            if (x()-puntuacion > 0){
                velocidadx = -(puntuacion+2);
            }else{
                velocidadx = 0;
            }
            break;
        case 'd':
            if (x()+puntuacion < 562){
                velocidadx = puntuacion+2;
            }else{
                velocidadx = 0;
            }
            break;
        case 'n':
            velocidadx = 0;
            velocidady = 0;
            break;
        default:
            break;
        }
    }
        break;
    case 'b':{
        velocidadx = 0;
        switch (direccion) {
        case 'w':{
            if (y()-puntuacion > 0){
                velocidady = -(puntuacion);
            }else{
                velocidady = 0;
            }
        }
            break;
        case 's':{
            if (y()+puntuacion < 310){
                velocidady = puntuacion;
            }else{
                velocidady = 0;
            }
        }
            break;
        case 'd':{
            velocidadx = 0;
            velocidady = 0;
        }
            break;
        case 'a':{
            velocidadx = 0;
            velocidady = 0;
        }
        break;
        case 'n':
            velocidadx = 0;
            velocidady = 0;
            break;
        default:
            break;
        }
    }
    break;
    case 'd':{
        velocidadx = 0;
        switch (direccion) {
        case 'w':{
            if (y()-puntuacion > 0){
                velocidady = -(puntuacion);
            }else{
                velocidady = 0;
            }
        }
        break;
        case 's':{
            if (y()+puntuacion < 310){
                velocidady = puntuacion;
            }else{
                velocidady = 0;
            }
        }
        break;
        case 'd':{
            velocidadx = 0;
            velocidady = 0;
        }
        break;
        case 'a':{
            velocidadx = 0;
            velocidady = 0;
        }
        break;
        case 'n':
            velocidadx = 0;
            velocidady = 0;
            break;
        default:
            break;
        }
    }
    break;
    case 'n':{
        velocidady = 0;
        velocidadx = 0;
        }
        break;
    default:
        break;
    }
}

void player::reset_vidas()
{
    vidas = 3;
}
