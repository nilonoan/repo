#ifndef MYQTQUICKVIEW_H
#define MYQTQUICKVIEW_H

#include <QObject>
#include <QtQuick/QQuickView>

#include <QQuickItem>

class MyQtQuickView : public QQuickView
{
    Q_OBJECT
    Q_PROPERTY(QString myProperty READ prop WRITE setProp NOTIFY propChanged)
public:
    explicit MyQtQuickView(QWindow *parent = 0);

    QString prop() { return m_myProperty; }

    void setProp(QString newStr){ m_myProperty = newStr; emit propChanged(); }

    Q_INVOKABLE bool printDebugMsgInvokable(const QString &msg) {
        qDebug() << "Called the invokable C++ method with" << msg;
        return true;
    }

signals:
    void propChanged(void);

public slots:
    void printDebugMsg(QString msg);

private:
    QString m_myProperty;
};

#endif // MYQTQUICKVIEW_H
