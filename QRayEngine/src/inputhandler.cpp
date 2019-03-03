#include "inputhandler.h"

InputHandler::InputHandler(ActorPosition *actorPosition, ViewPlane *viewPlane)
{
    actorPositionToHandle = actorPosition;
    viewPlaneToHandle = viewPlane;
}

InputHandler::~InputHandler()
{
    delete actorPositionToHandle;
    actorPositionToHandle = nullptr;

    delete viewPlaneToHandle;
    viewPlaneToHandle = nullptr;
}

void InputHandler::inputEventMoveForward()
{

}

void InputHandler::inputEventMoveBackwards()
{

}

void InputHandler::inputEventTurnLeft()
{

}

void InputHandler::inputEventTurnRight()
{

}

void InputHandler::inputEventStrafeLeft()
{

}

void InputHandler::inputEventStrafeRight()
{

}
