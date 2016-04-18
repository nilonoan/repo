#include "mylibrary.h"

#include <QString>

class MyLibraryPrivate
{
public:
    MyLibraryPrivate();
    ~MyLibraryPrivate();
    QString m_name;
};


MyLibraryPrivate::MyLibraryPrivate()
    : m_name (QString())
{

}

MyLibraryPrivate::~MyLibraryPrivate()
{

}


MyLibrary::MyLibrary( QObject* parent )
    : QObject(parent)
    , d_ptr (new MyLibraryPrivate)
{
}

MyLibrary::~MyLibrary()
{

}

QString MyLibrary::readName() const
{
    Q_D (const MyLibrary);
    return d->m_name;
}

void MyLibrary::setName(const QString &name)
{
    Q_D (MyLibrary);
    d->m_name = name;
}
