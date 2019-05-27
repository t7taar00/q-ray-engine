#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include <QtGlobal>

class ViewPlane
{
public:
    ViewPlane();

    qreal getPlaneX() const;
    void setPlaneX(qreal value);

    qreal getPlaneY() const;
    void setPlaneY(qreal value);

private:
    qreal m_planeX;
    qreal m_planeY;
};

#endif // VIEWPLANE_H
