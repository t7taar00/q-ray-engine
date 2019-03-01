#ifndef RAYPROJECTILE_H
#define RAYPROJECTILE_H

#include <math.h>

#include "actorposition.h"
#include "viewplane.h"

class RayProjectile
{
public:
    double getRayDirX() const;
    double getRayDirY() const;

    void calcRayDirX(ActorPosition *actorPosition, ViewPlane *viewPlane, double cameraX);
    void calcRayDirY(ActorPosition *actorPosition, ViewPlane *viewPlane, double cameraX);

    void calcDeltaDistX();
    void calcDeltaDistY();

    int calcSideDistX(ActorPosition *actorPosition);
    int calcSideDistY(ActorPosition *actorPosition);

    int calcMapJump(ActorPosition *actorPosition, int stepX, int stepY);

private:
    double rayDirX;
    double rayDirY;

    double sideDistX;
    double sideDistY;

    double deltaDistX;
    double deltaDistY;
};

#endif // RAYPROJECTILE_H
