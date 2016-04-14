#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickView>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml"))); //si uso esto en vez de component.create (mas abajo) me tira: ReferenceError: myProperty is not defined

    MyClass myClass;
    myClass.setProp("primer seteo de texto en main.cpp");


    QQmlContext *context = engine.rootContext();


    context->setContextProperty("myMessages", &myClass);
    context->setContextObject(&myClass); //si comento esto me tira: ReferenceError: myProperty is not defined


    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickWindow * topLevel = qobject_cast<QQuickWindow*>(component.create(context));
    topLevel->show();


    return app.exec();
}
