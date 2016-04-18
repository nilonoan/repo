#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include "mylibrary_global.h"
#include <QObject>
#include <QScopedPointer>

class MyLibraryPrivate;

class MYLIBRARYSHARED_EXPORT MyLibrary : public QObject
{
    Q_OBJECT

    Q_PROPERTY (QString name READ readName WRITE setName NOTIFY nameChanged)

public:
    MyLibrary( QObject *parent = 0);
    ~MyLibrary();
    QString readName() const;
    void setName(const QString &name);
private:

    QScopedPointer<MyLibraryPrivate> const d_ptr;

    Q_DECLARE_PRIVATE (MyLibrary)
signals:
    void nameChanged(void);
};

#endif // MYLIBRARY_H
