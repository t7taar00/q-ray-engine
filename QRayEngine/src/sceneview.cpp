#include "sceneview.h"

SceneView::SceneView(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0, 0, SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT);
    this->setFocusPolicy(Qt::StrongFocus);

    actorPosition = new ActorPosition;
    viewPlane = new ViewPlane;

    inputHandler = new InputHandler(actorPosition, viewPlane);
}

SceneView::~SceneView()
{
    delete actorPosition;
    actorPosition = nullptr;

    delete viewPlane;
    viewPlane = nullptr;

    delete inputHandler;
    inputHandler = nullptr;
}

void SceneView::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if(event->key() == Qt::Key_A)
        inputHandler->inputEventTurnLeft();
    if(event->key() == Qt::Key_D)
        inputHandler->inputEventTurnRight();
    if(event->key() == Qt::Key_W)
        inputHandler->inputEventMoveForward();
    if(event->key() == Qt::Key_S)
        inputHandler->inputEventMoveBackwards();
    if(event->key() == Qt::Key_Q)
        inputHandler->inputEventStrafeLeft();
    if(event->key() == Qt::Key_E)
        inputHandler->inputEventStrafeRight();
}
