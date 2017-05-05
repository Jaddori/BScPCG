#ifndef GLWIDGET_H
#define GLWIDGET_H

#if _WIN32
#include "GL/glew.h"
#else
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#endif

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include "Assets.h"
#include "Renderer.h"
#include "Elicras.h"

using namespace Assets;
using namespace Rendering;
using namespace PCG;
using namespace Utilities;

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
    void mouseReleaseEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private:
    static const int CITY_WIDTH = 30;
    static const int CITY_HEIGHT = 30;

    AssetManager assets;
    Renderer renderer;

    int fontTexture;
    Assets::Font* font;

    Elicras elicras;

    int mouseX, mouseY;
};

#endif // GLWIDGET_H
