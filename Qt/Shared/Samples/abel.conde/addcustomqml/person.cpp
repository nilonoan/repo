#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &n)
{
    m_name = n;
}

float Person::height() const
{
    return m_height;
}

void Person::setHeight(const float &n)
{
    m_height = n;
}

int Person::weight() const
{
    return m_weight;
}

void Person::setWeight(const int &n)
{
    m_weight = n;
}

QString Person::color_hair() const
{
    return m_color_hair;
}

void Person::setColorHair(const QString &n)
{
    m_color_hair = n;
}
