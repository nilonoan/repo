#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore/QPluginLoader>
#include <QtQml/QQmlExtensionPlugin>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QPluginLoader *pluginloader = new QPluginLoader;
    QQmlExtensionPlugin *plugin;

    pluginloader->setFileName("C:\\Users\\laura.e.lucas.alday\\Documents\\build-testPlugins-Desktop_Qt_5_6_0_MinGW_32bit-Debug\\MyUtilities\\debug\\MyUtilitiesd.dll");
    plugin = qobject_cast<QQmlExtensionPlugin *>(pluginloader->instance());

    if ( plugin ) {
        plugin->registerTypes("com.mycompany.qmlcomponents");
        qDebug() << "plugin loaded";
    } else {
        qDebug() << "plugin failed to load";
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
