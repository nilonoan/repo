#include <QApplication>
#include <QQmlApplicationEngine>
#include "myqtquickview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyQtQuickView view;
    view.setProp("Hello world");
    view.show();

    return app.exec();
}
