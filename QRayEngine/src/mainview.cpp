#include "mainview.h"

MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    this->setStyleSheet("background-color: black;");

    sceneView = new SceneView(this);
    sceneView->show();

    // TODO: figure out a better way to express the dimensions later on

    uiImageLoader = QPixmap(640, 120);
    uiImageLoader.load(":/texture/texture/ui_bottom.png");

    uiBottom = new QLabel(this);
    uiBottom->setPixmap(uiImageLoader);
    uiBottom->setGeometry(0, 480, 640, 120);

    uiImageLoader = QPixmap(160, 600);
    uiImageLoader.load(":/texture/texture/ui_right.png");

    uiRight = new QLabel(this);
    uiRight->setPixmap(uiImageLoader);
    uiRight->setGeometry(640, 0, 160, 600);
}

MainView::~MainView()
{
    delete sceneView;
    sceneView = nullptr;

    delete uiBottom;
    uiBottom = nullptr;

    delete uiRight;
    uiRight = nullptr;
}
