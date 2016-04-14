#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QQmlListProperty>

#include "car.h"
#include "person.h"

// ![0]
class Item : public QObject
{
    Q_OBJECT
// ![0]
// ![1]
    Q_PROPERTY(QQmlListProperty<Person> persons READ persons)
// ![1]
// ![2]
    Q_PROPERTY(QQmlListProperty<Car> cars READ cars)
// ![2]
// ![3]

public:
    explicit Item(QObject *parent = 0);

    QQmlListProperty<Person> persons();
    int personCount() const;
    Person *person(int) const;

    QQmlListProperty<Car> cars();
    int carCount() const;
    Car *car(int) const;

signals:

public slots:

private:
    QList<Person *> m_persons;
    QList<Car *> m_cars;
};
// ![3]

#endif // ITEM_H
