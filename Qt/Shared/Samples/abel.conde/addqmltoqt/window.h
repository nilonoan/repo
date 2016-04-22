#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>

#include "person.h"

class Window : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Person* persona READ persona WRITE setPersona)

public:
    Window(QObject *parent = 0);

    Person* persona() const;
    void setPersona(Person *persona);

signals:

public slots:

private:
    Person *m_persona;
};

#endif // WINDOW_H
