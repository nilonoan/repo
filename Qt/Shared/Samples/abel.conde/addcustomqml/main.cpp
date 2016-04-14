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

    qDebug() << "Printing Persons.....";
    qDebug() << "";

    for (ii = 0; ii < item->personCount(); ++ ii)
    {
        qDebug() << "::::::Person::::::";
        qDebug() << "";
        qDebug() << "Name: " << item->person(ii)->name();
        qDebug() << "Color Hair: " << item->person(ii)->color_hair();
        qDebug() << "";
        qDebug() << "::::::::::::::::::";
        qDebug() << "";
    }

    qDebug() << "";
    qDebug() << "";
    qDebug() << "Printing Cars.....";
    qDebug() << "";

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
