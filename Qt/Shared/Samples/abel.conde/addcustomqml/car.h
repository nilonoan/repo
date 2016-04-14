#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject
{
    Q_OBJECT   
    Q_PROPERTY(QString color READ color WRITE setColor)
    Q_PROPERTY(QString model READ model WRITE setModel)
    Q_PROPERTY(int amount_doors READ amount_doors WRITE setAmountDoors)

public:
    explicit Car(QObject *parent = 0);    

    QString color() const;
    void setColor(const QString &);

    QString model() const;
    void setModel(const QString &);

    int amount_doors() const;
    void setAmountDoors(const int &);
signals:

public slots:

private:
    QString m_color;
    QString m_model;
    int m_amount_doors;
};

#endif // CAR_H
