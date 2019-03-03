#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#define SCENE_VIEW_WIDTH 640
#define SCENE_VIEW_HEIGHT 480

#include <QWidget>

class SceneView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SCENEVIEW_H
