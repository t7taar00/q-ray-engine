#include "sceneview.h"

SceneView::SceneView(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT);
}
