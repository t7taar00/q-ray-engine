#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <QtGlobal>
#include <QWidget>

class RenderEngine
{
public:
    RenderEngine(QWidget *parent = nullptr, QImage *buffer = nullptr);
    ~RenderEngine();

    void calculateFrame();

private:

};

#endif // RENDERENGINE_H
