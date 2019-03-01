#include "actorposition.h"

ActorPosition::ActorPosition()
{
    posX = 22;
    posY = 12;

    dirX = -1;
    dirY = 0;
}

double ActorPosition::getPosX() const
{
    return posX;
}

void ActorPosition::setPosX(double value)
{
    posX = value;
}

double ActorPosition::getPosY() const
{
    return posY;
}

void ActorPosition::setPosY(double value)
{
    posY = value;
}

double ActorPosition::getDirX() const
{
    return dirX;
}

void ActorPosition::setDirX(double value)
{
    dirX = value;
}

double ActorPosition::getDirY() const
{
    return dirY;
}

void ActorPosition::setDirY(double value)
{
    dirY = value;
}
