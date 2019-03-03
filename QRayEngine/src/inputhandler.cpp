#include "inputhandler.h"

InputHandler::InputHandler(ActorPosition *actorPosition, ViewPlane *viewPlane)
{
    a = actorPosition;
    v = viewPlane;
}

InputHandler::~InputHandler()
{
    delete a;
    a = nullptr;

    delete v;
    v = nullptr;
}

void InputHandler::inputEventMoveForward()
{
    if(SceneMap::mapArray[static_cast<int>(a->getPosX() + a->getDirX() * A::moveSpeed)]
                         [static_cast<int>(a->getPosY())] == 0)
    {
        a->setPosX(a->getPosX() + a->getDirX() * A::moveSpeed);
    }

    if(SceneMap::mapArray[static_cast<int>(a->getPosX())]
                         [static_cast<int>(a->getPosY() + a->getDirY() * A::moveSpeed)] == 0)
    {
        a->setPosY(a->getPosY() + a->getDirY() * A::moveSpeed);
    }
}

void InputHandler::inputEventMoveBackwards()
{
    if(SceneMap::mapArray[static_cast<int>(a->getPosX() - a->getDirX() * A::moveSpeed)]
                         [static_cast<int>(a->getPosY())] == 0)
    {
        a->setPosX(a->getPosX() - a->getDirX() * A::moveSpeed);
    }

    if(SceneMap::mapArray[static_cast<int>(a->getPosX())]
                         [static_cast<int>(a->getPosY() - a->getDirY() * A::moveSpeed)] == 0)
    {
        a->setPosY(a->getPosY() - a->getDirY() * A::moveSpeed);
    }
}

void InputHandler::inputEventTurnLeft()
{
    double oldDirX = a->getDirX();
    a->setDirX(a->getDirX() * std::cos(A::rotateSpeed) - a->getDirY() * std::sin(A::rotateSpeed));
    a->setDirY(oldDirX * std::sin(A::rotateSpeed) + a->getDirY() * std::cos(A::rotateSpeed));

    double oldPlaneX = v->getPlaneX();
    v->setPlaneX(v->getPlaneX() * std::cos(A::rotateSpeed) - v->getPlaneY() * std::sin(A::rotateSpeed));
    v->setPlaneY(oldPlaneX * std::sin(A::rotateSpeed) + v->getPlaneY() * std::cos(A::rotateSpeed));
}

void InputHandler::inputEventTurnRight()
{
    double oldDirX = a->getDirX();
    a->setDirX(a->getDirX() * std::cos(-A::rotateSpeed) - a->getDirY() * std::sin(-A::rotateSpeed));
    a->setDirY(oldDirX * std::sin(-A::rotateSpeed) + a->getDirY() * std::cos(-A::rotateSpeed));

    double oldPlaneX = v->getPlaneX();
    v->setPlaneX(v->getPlaneX() * std::cos(-A::rotateSpeed) - v->getPlaneY() * std::sin(-A::rotateSpeed));
    v->setPlaneY(oldPlaneX * std::sin(-A::rotateSpeed) + v->getPlaneY() * std::cos(-A::rotateSpeed));
}

void InputHandler::inputEventStrafeLeft()
{
    if(SceneMap::mapArray[static_cast<int>(a->getPosX() - v->getPlaneX() * A::moveSpeed)]
                         [static_cast<int>(a->getPosY())] == 0)
    {
        a->setPosX(a->getPosX() - v->getPlaneX() * A::moveSpeed);
    }
    if(SceneMap::mapArray[static_cast<int>(a->getPosX())]
                         [static_cast<int>(a->getPosY() - v->getPlaneY() * A::moveSpeed)] == 0)
    {
        a->setPosY(a->getPosY() - v->getPlaneY() * A::moveSpeed);
    }
}

void InputHandler::inputEventStrafeRight()
{
    if(SceneMap::mapArray[static_cast<int>(a->getPosX() + v->getPlaneX() * A::moveSpeed)]
                         [static_cast<int>(a->getPosY())] == 0)
    {
        a->setPosX(a->getPosX() + v->getPlaneX() * A::moveSpeed);
    }
    if(SceneMap::mapArray[static_cast<int>(a->getPosX())]
                         [static_cast<int>(a->getPosY() + v->getPlaneY() * A::moveSpeed)] == 0)
    {
        a->setPosY(a->getPosY() + v->getPlaneY() * A::moveSpeed);
    }
}
