#include "mainview.h"

MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    sceneView = new SceneView;
}

MainView::~MainView()
{
    delete sceneView;
    sceneView = nullptr;
}
