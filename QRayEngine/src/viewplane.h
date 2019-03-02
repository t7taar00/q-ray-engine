#ifndef VIEWPLANE_H
#define VIEWPLANE_H

class ViewPlane
{
public:
    ViewPlane();

    double getPlaneX() const;
    void setPlaneX(double value);

    double getPlaneY() const;
    void setPlaneY(double value);

private:
    double planeX;
    double planeY;
};

#endif // VIEWPLANE_H
