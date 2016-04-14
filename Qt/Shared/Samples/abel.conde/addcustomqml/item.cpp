#include "item.h"

Item::Item(QObject *parent) : QObject(parent)
{
}

QQmlListProperty<Person> Item::persons()
{
    return QQmlListProperty<Person>(this, m_persons);
}

int Item::personCount() const
{
    return m_persons.count();
}

Person *Item::person(int index) const
{
    return m_persons.at(index);
}

QQmlListProperty<Car> Item::cars()
{
    return QQmlListProperty<Car>(this, m_cars);
}

int Item::carCount() const
{
    return m_cars.count();
}

Car *Item::car(int index) const
{
    return m_cars.at(index);
}
