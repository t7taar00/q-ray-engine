#include "actorposition.h"

const qreal ActorPosition::moveSpeed(0.2);
const qreal ActorPosition::rotateSpeed(0.05);

ActorPosition::ActorPosition()
    : m_posX(22)
    , m_posY(12)
    , m_dirX(-1)
    , m_dirY(0)
{
}

qreal ActorPosition::getPosX() const
{
    return m_posX;
}

void ActorPosition::setPosX(qreal value)
{
    m_posX = value;
}

qreal ActorPosition::getPosY() const
{
    return m_posY;
}

void ActorPosition::setPosY(qreal value)
{
    m_posY = value;
}

qreal ActorPosition::getDirX() const
{
    return m_dirX;
}

void ActorPosition::setDirX(qreal value)
{
    m_dirX = value;
}

qreal ActorPosition::getDirY() const
{
    return m_dirY;
}

void ActorPosition::setDirY(qreal value)
{
    m_dirY = value;
}

quint8 ActorPosition::getMapX() const
{
    return m_mapX;
}

void ActorPosition::setMapX(quint8 value)
{
    m_mapX = value;
}

quint8 ActorPosition::getMapY() const
{
    return m_mapY;
}

void ActorPosition::setMapY(quint8 value)
{
    m_mapY = value;
}
