#include "window.h"

Window::Window(QObject *parent) : QObject(parent)
{
}

Person* Window::persona() const
{
    return m_persona;
}

void Window::setPersona(Person *persona)
{
    m_persona = persona;
}
