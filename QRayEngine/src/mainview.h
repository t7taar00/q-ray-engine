#ifndef MAINVIEW_H
#define MAINVIEW_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define SCENE_VIEW_WIDTH 640
#define SCENE_VIEW_HEIGHT 480

#include <QMainWindow>

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();
};

#endif // MAINVIEW_H
