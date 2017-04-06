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

    glewExperimental = GL_TRUE;
    glewInit() == GLEW_OK;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    GLfloat vdata[] = { 0.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f };
    GLuint idata[] = { 0, 1, 2 };

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*6, vdata, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3, idata, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, 0);

    glBindVertexArray(0);
}

void GLWidget::paintGL()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
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
