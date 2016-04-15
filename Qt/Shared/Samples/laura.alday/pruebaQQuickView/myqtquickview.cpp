#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>


#include "myqtquickview.h"

MyQtQuickView::MyQtQuickView(QWindow *parent)
    : QQuickView(parent)
{

    rootContext()->setContextProperty(QStringLiteral("myViewerBackEnd"), this);
    rootContext()->setContextObject(this);
    QQmlEngine::setContextForObject(this, rootContext());

    setSource( QUrl(QStringLiteral("qrc:/myQMLFile.qml")) );
}

void MyQtQuickView::printDebugMsg(QString msg)
{
    qDebug() << "called the C++ public slot method with: " << msg;
}
