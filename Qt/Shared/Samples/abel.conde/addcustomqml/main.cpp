#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>

#include "item.h"
#include "car.h"
#include "person.h"

int main(int argc, char ** argv)
{
    QCoreApplication app(argc, argv);

    qmlRegisterType<Item>("Common", 1,0, "Item");
    qmlRegisterType<Person>("Common", 1,0, "Person");
    qmlRegisterType<Car>("Common", 1,0, "Car");

    QQmlEngine engine;

    QQmlComponent com_item(&engine, QUrl("qrc:item.qml"));
    Item *item = qobject_cast<Item *>(com_item.create());
    int ii = 0;

    qDebug() << "/////////////////////////////";
    qDebug() << "BEGIN: Item";
    qDebug() << "/////////////////////////////";
    qDebug() << "";

    qDebug() << "Printing Persons from QML and C++.....";
    qDebug() << "";

    item->personAdd(item->personCreate("[ new ] Jean Leno", 98, 1.77, "Black"));
    item->personAdd(item->personCreate("[ new ] John Simpson", 90, 1.70, "Blonde"));
    item->personAdd(item->personCreate("[ new ] Lero Jaret", 84, 1.80, "White"));

    item->personRemove(0);
    item->personRemove(item->personCount() - 1);
    item->personRemove(item->personCount() - 1);

    item->personUpdate(0, item->personCreate("[qml][updated] John Wesser", 89, 1.89, "White"));

    for (ii = 0; ii < item->personCount(); ++ ii)
    {
        qDebug() << "::::::Person::::::";
        qDebug() << "";
        qDebug() << "Name: " << item->person(ii)->name();
        qDebug() << "Weight: " << item->person(ii)->weight();
        qDebug() << "Height: " << item->person(ii)->height();
        qDebug() << "Color Hair: " << item->person(ii)->color_hair();
        qDebug() << "";
        qDebug() << "::::::::::::::::::";
        qDebug() << "";
    }

    qDebug() << "";
    qDebug() << "";
    qDebug() << "Printing Cars from QML and C++.....";
    qDebug() << "";

    item->carAdd(item->carCreate("[ new ] Blue", "Peugot", 4));
    item->carAdd(item->carCreate("[ new ] Yellow", "Fiat", 2));

    item->carRemove(0);
    item->carRemove(item->carCount() - 1);

    item->carUpdate(0, item->carCreate("[qml][updated] Red", "Fiat", 4));

    for (ii = 0; ii < item->carCount(); ++ii)
    {
        qDebug() << "::::::Car::::::";
        qDebug() << "";
        qDebug() << "Color: " << item->car(ii)->color();
        qDebug() << "Model: " << item->car(ii)->model();
        qDebug() << "Amount Doors: " << item->car(ii)->amount_doors();
        qDebug() << "";
        qDebug() << "::::::::::::::::::";
        qDebug() << "";
    }

    qDebug() << "/////////////////////////////";
    qDebug() << "END: Item";
    qDebug() << "/////////////////////////////";
    qDebug() << "";

    return app.exec();
}
