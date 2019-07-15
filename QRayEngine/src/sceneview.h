#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#define SCENE_VIEW_WIDTH 640
#define SCENE_VIEW_HEIGHT 480
#define HORIZONTAL_SKIP 2

#include <QtGlobal>
#include <QWidget>
#include <QKeyEvent>
#include <QBasicTimer>
#include <QPainter>

#include "renderengine.h"
#include "inputhandler.h"
#include "rayprojectile.h"
#include "texturereader.h"
#include "audiofx.h"

class SceneView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = nullptr);
    ~SceneView();

    void renderScene();

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *event);

private:
    QBasicTimer m_ticker;
    QImage m_buffer;

    RenderEngine *m_renderEngine;
    ActorPosition *m_actorPosition;
    ViewPlane *m_viewPlane;
    RayProjectile *m_rayProjectile;
    TextureReader *m_textureReader;
    InputHandler *m_inputHandler;
    AudioFX *m_musicFX;
};

#endif // SCENEVIEW_H
