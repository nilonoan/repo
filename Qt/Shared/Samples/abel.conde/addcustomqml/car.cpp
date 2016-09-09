#include "car.h"

Car::Car(QObject *parent) : QObject(parent)
{ //09428304923840923784237409327409237402397402397
}

QString Car::color() const
{
    return m_color;
}

void Car::setColor(const QString &n)
{
    m_color = n;
}

QString Car::model() const
{
    return m_model;
}

void Car::setModel(const QString &n)
{
    m_model = n;
}

int Car::amount_doors() const
{
    return m_amount_doors;
}

void Car::setAmountDoors(const int &n)
{
    m_amount_doors = n;
}
