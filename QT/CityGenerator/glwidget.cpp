#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setVersion(4,5);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);

    /*leftShiftKey = spaceKey = xKey = wKey = aKey = sKey = dKey = false;
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(10);*/
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    qDebug( "OpenGL Version: %s", glGetString(GL_VERSION) );

    // initalize GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    // setup OpenGL flags
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glDisable(GL_CULL_FACE);

    // load assets
    model = assets.LoadModel("./assets/models/valid_model.model");
    texture = assets.LoadTexture("./assets/textures/valid_texture.dds");

    // load the renderer
    renderer.Load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    renderer.AddElement(model, texture, glm::vec3(0.0f));
    renderer.Render(&assets);
}

void GLWidget::resizeGL(int w, int h)
{
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    /*int newX = event->localPos().x();
    int newY = event->localPos().y();
    deltaX = mouseX - newX;
    deltaY = mouseY - newY;
    mouseX = newX;
    mouseY = newY;

    rmb = event->buttons() & Qt::RightButton;*/
    event->ignore();
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    /*if( event->key() == Qt::Key_Space )
        spaceKey = true;
    else if( event->key() == Qt::Key_Shift )
        leftShiftKey = true;
    else if( event->key() == Qt::Key_X )
        xKey = true;
    else if( event->key() == Qt::Key_W )
        wKey = true;
    else if( event->key() == Qt::Key_A )
        aKey = true;
    else if( event->key() == Qt::Key_S )
        sKey = true;
    else if( event->key() == Qt::Key_D )
        dKey = true;
    else*/
        event->ignore();
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    /*if( event->key() == Qt::Key_Space )
        spaceKey = false;
    else if( event->key() == Qt::Key_Shift )
        leftShiftKey = false;
    else if( event->key() == Qt::Key_X )
        xKey = false;
    else if( event->key() == Qt::Key_W )
        wKey = false;
    else if( event->key() == Qt::Key_A )
        aKey = false;
    else if( event->key() == Qt::Key_S )
        sKey = false;
    else if( event->key() == Qt::Key_D )
        dKey = false;
    else*/
        event->ignore();
}
