#include "sceneview.h"

SceneView::SceneView(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0, 0, SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT);
    this->setFocusPolicy(Qt::StrongFocus);
}

SceneView::~SceneView()
{

}

void SceneView::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if(event->key() == Qt::Key_A)
        qDebug() << "A";
    if(event->key() == Qt::Key_D)
        qDebug() << "D";
    if(event->key() == Qt::Key_W)
        qDebug() << "W";
    if(event->key() == Qt::Key_S)
        qDebug() << "S";
    if(event->key() == Qt::Key_Q)
        qDebug() << "Q";
    if(event->key() == Qt::Key_E)
        qDebug() << "E";
}
