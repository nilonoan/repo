#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QSurfaceFormat>
#include <QDebug>

#include "window.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Window>("People", 1, 0, "Window");
    qmlRegisterType<Person>("People", 1, 0, "Person");

    QQmlApplicationEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);
    QObject::connect(&engine, SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));
    component->loadUrl(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *appWindow = component->create();

    //these three lines are simply to show that we can change the name value
    //of this
    QObject *persona = appWindow->findChild<QObject*>("persona");
    if (persona)
        persona->setProperty("name", "Blanco");

    //these three lines are simply to show that we can change the text value
    //of this
    QObject *label = appWindow->findChild<QObject*>("label");
    if (label)
        label->setProperty("text", QString("Ramon"));

    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    QSurfaceFormat surfaceFormat = window->requestedFormat();
    window->setFormat(surfaceFormat);
    window->show();

    return app.exec();
}
