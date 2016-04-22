#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(float height READ height WRITE setHeight)
    Q_PROPERTY(int weight READ weight WRITE setWeight)
    Q_PROPERTY(QString color_hair READ color_hair WRITE setColorHair)

public:
    Person(QObject *parent = 0);

    QString name() const;
    void setName(const QString &);

    float height() const;
    void setHeight(const float &);

    int weight() const;
    void setWeight(const int &);

    QString color_hair() const;
    void setColorHair(const QString &);

signals:

private:
    QString m_name;
    float m_height;
    int m_weight;
    QString m_color_hair;
};

#endif // PERSON_H
