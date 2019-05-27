#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QtGlobal>

#include <math.h>

#include "actorposition.h"
#include "viewplane.h"
#include "scenemap.h"

class InputHandler
{
public:
    InputHandler(ActorPosition *actorPosition, ViewPlane *viewPlane);
    ~InputHandler();

    bool checkForwardXCollision();
    bool checkForwardYCollision();

    bool checkBackwardsXCollision();
    bool checkBackwardsYCollision();

    bool checkLeftXCollition();
    bool checkLeftYCollition();

    bool checkRightXCollision();
    bool checkRightYCollision();

    void inputEventMoveForward();
    void inputEventMoveBackwards();

    void inputEventTurnLeft();
    void inputEventTurnRight();

    void inputEventStrafeLeft();
    void inputEventStrafeRight();

private:
    ActorPosition *m_actorPosition; // actorPosition instance
    ViewPlane *m_viewPlane;         // viewPlane instance
};

#endif // INPUTHANDLER_H
