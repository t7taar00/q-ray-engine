#include "mainview.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
{
    this->setStyleSheet("background-color: black;");

    m_sceneView = new SceneView(this);
    m_sceneView->show();

    // TODO: figure out a better way to express the dimensions later on

    m_uiImageLoader = QPixmap(640, 120);
    m_uiImageLoader.load(":/texture/texture/ui_bottom.png");

    m_uiBottom = new QLabel(this);
    m_uiBottom->setPixmap(m_uiImageLoader);
    m_uiBottom->setGeometry(0, 480, 640, 120);

    m_uiImageLoader = QPixmap(160, 600);
    m_uiImageLoader.load(":/texture/texture/ui_right.png");

    m_uiRight = new QLabel(this);
    m_uiRight->setPixmap(m_uiImageLoader);
    m_uiRight->setGeometry(640, 0, 160, 600);
}

MainView::~MainView()
{
    delete m_sceneView;
    m_sceneView = nullptr;

    delete m_uiBottom;
    m_uiBottom = nullptr;

    delete m_uiRight;
    m_uiRight = nullptr;
}
