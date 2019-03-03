#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "actorposition.h"
#include "viewplane.h"

class InputHandler
{
public:
    InputHandler(ActorPosition *actorPosition, ViewPlane *viewPlane);
    ~InputHandler();

    void inputEventMoveForward();
    void inputEventMoveBackwards();

    void inputEventTurnLeft();
    void inputEventTurnRight();

    void inputEventStrafeLeft();
    void inputEventStrafeRight();

private:
    ActorPosition *actorPositionToHandle;
    ViewPlane *viewPlaneToHandle;
};

#endif // INPUTHANDLER_H
