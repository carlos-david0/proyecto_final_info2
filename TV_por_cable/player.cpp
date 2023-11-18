#include "player.h"

player::player()
{
    vidas = 3;
}

void player::setdireccion(char direccion)
{
    this->direccion = direccion;
}

void player::setimage(char minijuego)
{
    switch (minijuego) {
    case 'c':
        setPixmap(QPixmap(":/imagenes/canasta.png").scaled(100, 100));
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
