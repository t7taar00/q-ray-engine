#ifndef MAINVIEW_H
#define MAINVIEW_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <QMainWindow>
#include <QLabel>

#include "sceneview.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();

private:
    QPixmap uiImageLoader;

    SceneView *sceneView;
    QLabel *uiBottom;
    QLabel *uiRight;
};

#endif // MAINVIEW_H
