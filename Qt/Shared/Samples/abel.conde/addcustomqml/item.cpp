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

Person *Item::personCreate(QString name, int weight, float height, QString color_hair)
{
    Person *ob = new Person();

    ob->setName(name);
    ob->setWeight(weight);
    ob->setHeight(height);
    ob->setColorHair(color_hair);

    return ob;
}

void Item::personAdd(Person *ob)
{
    m_persons.append(ob);
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

void Item::carAdd(Car *ob)
{
    m_cars.append(ob);
}

Car *Item::carCreate(QString color, QString model, int amount_doors)
{
    Car *ob = new Car();

    ob->setColor(color);
    ob->setModel(model);
    ob->setAmountDoors(amount_doors);

    return ob;
}
