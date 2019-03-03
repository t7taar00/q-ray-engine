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
