#include "mainview.h"

MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    sceneView = new SceneView(this);
    sceneView->show();
}

MainView::~MainView()
{
    delete sceneView;
    sceneView = nullptr;
}
