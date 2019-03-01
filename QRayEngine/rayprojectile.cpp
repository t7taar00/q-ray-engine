#include "rayprojectile.h"

double RayProjectile::getRayDirX() const
{
    return rayDirX;
}

double RayProjectile::getRayDirY() const
{
    return rayDirY;
}

void RayProjectile::calcRayDirX(ActorPosition actorPosition, ViewPlane viewPlane, double cameraX)
{
    rayDirX = actorPosition.getDirX() + viewPlane.getPlaneX() * cameraX;
}

void RayProjectile::calcRayDirY(ActorPosition actorPosition, ViewPlane viewPlane, double cameraX)
{
    rayDirY = actorPosition.getDirY() + viewPlane.getPlaneY() * cameraX;
}

void RayProjectile::calcDeltaDistX()
{
    deltaDistX = std::abs(1.0 / rayDirX);
}

void RayProjectile::calcDeltaDistY()
{
    deltaDistY = std::abs(1.0 / rayDirY);
}

int RayProjectile::calcSideDistX(ActorPosition actorPosition)
{
    if(rayDirX < 0)
    {
        sideDistX = (actorPosition.getPosX() - actorPosition.getMapX()) * deltaDistX;
        return -1;
    }
    else
    {
        sideDistX = (actorPosition.getMapX() + 1.0 - actorPosition.getPosX()) * deltaDistX;
        return 1;
    }
}

int RayProjectile::calcSideDistY(ActorPosition actorPosition)
{
    if(rayDirY < 0)
    {
        sideDistY = (actorPosition.getPosY() - actorPosition.getMapY()) * deltaDistY;
        return -1;
    }
    else
    {
        sideDistY = (actorPosition.getMapY() + 1.0 - actorPosition.getPosY()) * deltaDistY;
        return 1;
    }
}

int RayProjectile::calcMapJump(ActorPosition actorPosition, int stepX, int stepY)
{
    if(sideDistX < sideDistY)
    {
        sideDistX += deltaDistX;
        actorPosition.setMapX(actorPosition.getMapX() + stepX);
        return 0;
    }
    else
    {
        sideDistY += deltaDistY;
        actorPosition.setMapY(actorPosition.getMapY() + stepY);
        return 1;
    }
}
