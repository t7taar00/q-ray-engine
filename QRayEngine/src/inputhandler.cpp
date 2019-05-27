#include "inputhandler.h"

InputHandler::InputHandler(ActorPosition *actorPosition, ViewPlane *viewPlane)
    : m_actorPosition(actorPosition)
    , m_viewPlane(viewPlane)
{
}

InputHandler::~InputHandler()
{
    delete m_actorPosition;
    m_actorPosition = nullptr;

    delete m_viewPlane;
    m_viewPlane = nullptr;
}

bool InputHandler::checkForwardXCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX()
        + m_actorPosition->getDirX() * ActorPosition::moveSpeed);

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY());

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkForwardYCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX());

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY()
        + m_actorPosition->getDirY() * ActorPosition::moveSpeed);

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkBackwardsXCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX()
        - m_actorPosition->getDirX() * ActorPosition::moveSpeed);

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY());

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkBackwardsYCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX());

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY()
        - m_actorPosition->getDirY() * ActorPosition::moveSpeed);

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkLeftXCollition()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX()
        - m_viewPlane->getPlaneX() * ActorPosition::moveSpeed);

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY());

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkLeftYCollition()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX());

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY()
        - m_viewPlane->getPlaneY() * ActorPosition::moveSpeed);

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkRightXCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX()
        + m_viewPlane->getPlaneX() * ActorPosition::moveSpeed);

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY());

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

bool InputHandler::checkRightYCollision()
{
    quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX());

    quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY()
        + m_viewPlane->getPlaneY() * ActorPosition::moveSpeed);

    if (SceneMap::mapArray[mapX][mapY] == 0)
        return false;
    else
        return true;
}

void InputHandler::inputEventMoveForward()
{
    if (!checkForwardXCollision()) {
        m_actorPosition->setPosX(m_actorPosition->getPosX()
            + m_actorPosition->getDirX() * ActorPosition::moveSpeed);
    }

    if (!checkForwardYCollision()) {
        m_actorPosition->setPosY(m_actorPosition->getPosY()
            + m_actorPosition->getDirY() * ActorPosition::moveSpeed);
    }
}

void InputHandler::inputEventMoveBackwards()
{
    if (!checkBackwardsXCollision()) {
        m_actorPosition->setPosX(m_actorPosition->getPosX()
            - m_actorPosition->getDirX() * ActorPosition::moveSpeed);
    }

    if (!checkBackwardsYCollision()) {
        m_actorPosition->setPosY(m_actorPosition->getPosY()
            - m_actorPosition->getDirY() * ActorPosition::moveSpeed);
    }
}

void InputHandler::inputEventTurnLeft()
{
    qreal oldDirX = m_actorPosition->getDirX();

    m_actorPosition->setDirX(m_actorPosition->getDirX()
        * std::cos(ActorPosition::rotateSpeed) - m_actorPosition->getDirY()
        * std::sin(ActorPosition::rotateSpeed));

    m_actorPosition->setDirY(oldDirX * std::sin(ActorPosition::rotateSpeed)
        + m_actorPosition->getDirY() * std::cos(ActorPosition::rotateSpeed));

    qreal oldPlaneX = m_viewPlane->getPlaneX();

    m_viewPlane->setPlaneX(m_viewPlane->getPlaneX()
        * std::cos(ActorPosition::rotateSpeed) - m_viewPlane->getPlaneY()
        * std::sin(ActorPosition::rotateSpeed));

    m_viewPlane->setPlaneY(oldPlaneX * std::sin(ActorPosition::rotateSpeed)
        + m_viewPlane->getPlaneY() * std::cos(ActorPosition::rotateSpeed));
}

void InputHandler::inputEventTurnRight()
{
    qreal oldDirX = m_actorPosition->getDirX();

    m_actorPosition->setDirX(m_actorPosition->getDirX()
        * std::cos(-ActorPosition::rotateSpeed) - m_actorPosition->getDirY()
        * std::sin(-ActorPosition::rotateSpeed));

    m_actorPosition->setDirY(oldDirX * std::sin(-ActorPosition::rotateSpeed)
        + m_actorPosition->getDirY() * std::cos(-ActorPosition::rotateSpeed));

    qreal oldPlaneX = m_viewPlane->getPlaneX();

    m_viewPlane->setPlaneX(m_viewPlane->getPlaneX()
        * std::cos(-ActorPosition::rotateSpeed) - m_viewPlane->getPlaneY()
        * std::sin(-ActorPosition::rotateSpeed));

    m_viewPlane->setPlaneY(oldPlaneX * std::sin(-ActorPosition::rotateSpeed)
        + m_viewPlane->getPlaneY() * std::cos(-ActorPosition::rotateSpeed));
}

void InputHandler::inputEventStrafeLeft()
{
    if (!checkLeftXCollition()) {
        m_actorPosition->setPosX(m_actorPosition->getPosX()
            - m_viewPlane->getPlaneX() * ActorPosition::moveSpeed);
    }
    if (!checkLeftYCollition()) {
        m_actorPosition->setPosY(m_actorPosition->getPosY()
            - m_viewPlane->getPlaneY() * ActorPosition::moveSpeed);
    }
}

void InputHandler::inputEventStrafeRight()
{
    if (!checkRightXCollision()) {
        m_actorPosition->setPosX(m_actorPosition->getPosX()
            + m_viewPlane->getPlaneX() * ActorPosition::moveSpeed);
    }
    if (!checkRightYCollision()) {
        m_actorPosition->setPosY(m_actorPosition->getPosY()
            + m_viewPlane->getPlaneY() * ActorPosition::moveSpeed);
    }
}
