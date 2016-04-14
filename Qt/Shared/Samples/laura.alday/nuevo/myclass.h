#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myProperty READ prop WRITE setProp NOTIFY propChanged)


public:
    explicit MyClass(QObject *parent = 0);

    QString prop() {
        return m_myProperty;
    }

    void setProp(QString newStr){
        m_myProperty = newStr; emit propChanged();
    }

    Q_INVOKABLE bool postMessage(const QString &msg) {
        qDebug() << "Called the C++ method with" << msg;
        return true;
    }

signals:
 void propChanged(void);

public slots:
    void refresh() {
        QList<int> lista;
        lista << 1;
        lista << 8;
        lista << 341;
        foreach (int i, lista){
            qDebug() << "Called the C++ slot " << i << " and we have foreach keyword!";
        }
    }

private:
    QString m_myProperty;


};

#endif // MYCLASS_H
