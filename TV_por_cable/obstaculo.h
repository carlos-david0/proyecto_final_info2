#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class obstaculo: public QObject, public QGraphicsPixmapItem
{
public:
    obstaculo();
};

#endif // OBSTACULO_H
