#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#define SCENE_VIEW_WIDTH 640
#define SCENE_VIEW_HEIGHT 480

#include <QWidget>
#include <QKeyEvent>

#include "inputhandler.h"

class SceneView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = nullptr);
    ~SceneView();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    ActorPosition *actorPosition;
    ViewPlane *viewPlane;
    InputHandler *inputHandler;
};

#endif // SCENEVIEW_H
