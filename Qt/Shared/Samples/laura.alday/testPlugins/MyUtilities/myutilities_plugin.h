#ifndef MYUTILITIES_PLUGIN_H
#define MYUTILITIES_PLUGIN_H

#include <QQmlExtensionPlugin>

class MyUtilitiesPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // MYUTILITIES_PLUGIN_H
