#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#define SCENE_VIEW_WIDTH 640
#define SCENE_VIEW_HEIGHT 480

#include <QWidget>
#include <QKeyEvent>
#include <QBasicTimer>
#include <QPainter>

#include "inputhandler.h"
#include "rayprojectile.h"
#include "texturereader.h"

class SceneView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = nullptr);
    ~SceneView();

    void renderScene();

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent*);
    void paintEvent(QPaintEvent *event);

private:
    QBasicTimer ticker;
    QImage buffer;

    ActorPosition *actorPosition;
    ViewPlane *viewPlane;
    RayProjectile *rayProjectile;
    TextureReader *textureReader;
    InputHandler *inputHandler;
};

#endif // SCENEVIEW_H
