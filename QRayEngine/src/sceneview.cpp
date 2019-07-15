#include "sceneview.h"

SceneView::SceneView(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(0, 0, SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setCursor(Qt::CrossCursor);

    m_renderEngine = new RenderEngine;

    m_buffer = QImage(SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT,
        QImage::Format_RGB32);

    m_ticker.start(20, this);

    m_musicFX = new AudioFX(":/music/music/tune.wav", QSound::Infinite);
    m_musicFX->playAudio();
}

SceneView::~SceneView()
{
    delete m_renderEngine;
    m_renderEngine = nullptr;

    delete m_musicFX;
    m_musicFX = nullptr;
}

void SceneView::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if (event->key() == Qt::Key_A)
        m_inputHandler->inputEventTurnLeft();
    if (event->key() == Qt::Key_D)
        m_inputHandler->inputEventTurnRight();
    if (event->key() == Qt::Key_W)
        m_inputHandler->inputEventMoveForward();
    if (event->key() == Qt::Key_S)
        m_inputHandler->inputEventMoveBackwards();
    if (event->key() == Qt::Key_Q)
        m_inputHandler->inputEventStrafeLeft();
    if (event->key() == Qt::Key_E)
        m_inputHandler->inputEventStrafeRight();
}

void SceneView::timerEvent(QTimerEvent *)
{
    renderScene();
}

void SceneView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawImage(0, 0, m_buffer);
    p.end();
}

void SceneView::renderScene()
{

}
