#ifndef MAINVIEW_H
#define MAINVIEW_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <QMainWindow>

#include "sceneview.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();

private:
    SceneView *sceneView;
};

#endif // MAINVIEW_H
