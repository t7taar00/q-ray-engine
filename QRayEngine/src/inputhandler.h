#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <math.h>

#include "actorposition.h"
#include "viewplane.h"
#include "scenemap.h"

class InputHandler
{
    typedef ActorPosition A; // just to make the long bits where
                             // static access is used more readable
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
    ActorPosition *a; // actorPosition instance to be modified by input
    ViewPlane *v;     // viewPlane instance to be modified by input
};

#endif // INPUTHANDLER_H
