#include "viewplane.h"

ViewPlane::ViewPlane()
{
    planeX = 0;
    planeY = 0.66;
}

double ViewPlane::getPlaneX() const
{
    return planeX;
}

void ViewPlane::setPlaneX(double value)
{
    planeX = value;
}

double ViewPlane::getPlaneY() const
{
    return planeY;
}

void ViewPlane::setPlaneY(double value)
{
    planeY = value;
}
