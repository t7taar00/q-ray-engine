#include "viewplane.h"

ViewPlane::ViewPlane()
{
    m_planeX = 0;
    m_planeY = 0.66;
}

qreal ViewPlane::getPlaneX() const
{
    return m_planeX;
}

void ViewPlane::setPlaneX(qreal value)
{
    m_planeX = value;
}

qreal ViewPlane::getPlaneY() const
{
    return m_planeY;
}

void ViewPlane::setPlaneY(qreal value)
{
    m_planeY = value;
}
