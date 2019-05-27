#include "rayprojectile.h"

qreal RayProjectile::getRayDirX() const
{
    return m_rayDirX;
}

qreal RayProjectile::getRayDirY() const
{
    return m_rayDirY;
}

void RayProjectile::calcRayDirX(ActorPosition *actorPosition,
    ViewPlane *viewPlane, qreal cameraX)
{
    m_rayDirX = actorPosition->getDirX() + viewPlane->getPlaneX() * cameraX;
}

void RayProjectile::calcRayDirY(ActorPosition *actorPosition,
    ViewPlane *viewPlane, qreal cameraX)
{
    m_rayDirY = actorPosition->getDirY() + viewPlane->getPlaneY() * cameraX;
}

void RayProjectile::calcDeltaDistX()
{
    m_deltaDistX = std::abs(1.0 / m_rayDirX);
}

void RayProjectile::calcDeltaDistY()
{
    m_deltaDistY = std::abs(1.0 / m_rayDirY);
}

qint8 RayProjectile::calcSideDistX(ActorPosition *actorPosition)
{
    if (m_rayDirX < 0) {
        m_sideDistX = (actorPosition->getPosX()
            - actorPosition->getMapX()) * m_deltaDistX;
        return -1;
    } else {
        m_sideDistX = (actorPosition->getMapX() + 1.0
            - actorPosition->getPosX()) * m_deltaDistX;
        return 1;
    }
}

qint8 RayProjectile::calcSideDistY(ActorPosition *actorPosition)
{
    if (m_rayDirY < 0) {
        m_sideDistY = (actorPosition->getPosY()
            - actorPosition->getMapY()) * m_deltaDistY;
        return -1;
    } else {
        m_sideDistY = (actorPosition->getMapY() + 1.0
            - actorPosition->getPosY()) * m_deltaDistY;
        return 1;
    }
}

qint8 RayProjectile::calcMapJump(ActorPosition *actorPosition,
    qint8 stepX, qint8 stepY)
{
    if (m_sideDistX < m_sideDistY) {
        m_sideDistX += m_deltaDistX;
        actorPosition->setMapX(actorPosition->getMapX()
            + static_cast<quint8>(stepX));
        return 0;
    } else {
        m_sideDistY += m_deltaDistY;
        actorPosition->setMapY(actorPosition->getMapY()
            + static_cast<quint8>(stepY));
        return 1;
    }
}
