#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "GL/glew.h"
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include "Assets.h"
#include "Renderer.h"

using namespace Assets;
using namespace Rendering;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget* parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private:
   // QTimer timer;

    /*int mouseX, mouseY;
    float deltaX, deltaY;
    float mouseScroll;
    bool rmb;
    bool spaceKey, leftShiftKey;
    bool xKey, wKey, aKey, sKey, dKey;*/

    AssetManager assets;
    Renderer renderer;

    int model, texture;
};

#endif // GLWIDGET_H
