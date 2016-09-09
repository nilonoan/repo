#include "car.h"

Car::Car(QObject *parent) : QObject(parent)
{ //8888888888888888888811111
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
