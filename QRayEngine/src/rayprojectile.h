#ifndef RAYPROJECTILE_H
#define RAYPROJECTILE_H

#include <QtGlobal>

#include <math.h>

#include "actorposition.h"
#include "viewplane.h"

class RayProjectile
{
public:
    qreal getRayDirX() const;
    qreal getRayDirY() const;

    void calcRayDirX(ActorPosition *actorPosition, ViewPlane *viewPlane,
                     qreal cameraX);
    void calcRayDirY(ActorPosition *actorPosition, ViewPlane *viewPlane,
                     qreal cameraX);

    void calcDeltaDistX();
    void calcDeltaDistY();

    qint8 calcSideDistX(ActorPosition *actorPosition);
    qint8 calcSideDistY(ActorPosition *actorPosition);

    qint8 calcMapJump(ActorPosition *actorPosition,
                       qint8 stepX, qint8 stepY);

private:
    qreal m_rayDirX;
    qreal m_rayDirY;

    qreal m_sideDistX;
    qreal m_sideDistY;

    qreal m_deltaDistX;
    qreal m_deltaDistY;
};

#endif // RAYPROJECTILE_H
