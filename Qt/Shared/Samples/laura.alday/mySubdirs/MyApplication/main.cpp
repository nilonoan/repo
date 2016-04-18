#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "mylibrary.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyLibrary myLib;
    qDebug() << myLib.readName();
    myLib.setName("John Doe");
    qDebug() << myLib.readName();

    engine.rootContext()->setContextProperty("mylib", &myLib);
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.create();


    return app.exec();

   /*
    * esto no funciono : Unable to assign [undefined] to QString
    * porque desde el .qml trataba de usar MyData.name
    *
    QGuiApplication app(argc, argv);
      qmlRegisterType<MyLibrary>("MyLibr",1,0,"MyData");

    MyLibrary myLib;
    qDebug() << myLib.readName();
    myLib.setName("John Doe");
    qDebug() << myLib.readName();


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
     return app.exec();
*/


}
