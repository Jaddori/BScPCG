#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent), mouseX(-1), mouseY(-1)
{
    QSurfaceFormat format;
    format.setVersion(4,5);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);

    QSurfaceFormat::setDefaultFormat(format);

    /*leftShiftKey = spaceKey = xKey = wKey = aKey = sKey = dKey = false;
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(10);*/
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    qDebug("OpenGL Version: %s", glGetString(GL_VERSION));

#if _WIN32
    // initalize GLEW
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        qDebug("Failed to initialize GLEW.");
    }
#endif

    // setup OpenGL flags
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    // load assets
    model = assets.LoadModel("./assets/models/valid_model.model");
    texture = assets.LoadTexture("./assets/textures/valid_texture.dds");

    // load the renderer
    renderer.Load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::vec3 position(-20.0f, 0.0f, 0.0f);
    for(int i=0; i<10; i++)
    {
        renderer.AddElement(model, texture, position);
        position.x += 4.0f;
    }
    //renderer.AddElement(model, texture, glm::vec3(0.0f));
    renderer.Render(&assets);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        // get the position of the mouse cursor
        int newX = event->localPos().x();
        int newY = event->localPos().y();

        int deltaX = mouseX - newX;
        int deltaY = mouseY - newY;

        if(mouseX >= 0 && mouseY >= 0)
        {
            // move the camera with the mouse
            renderer.GetCamera()->UpdateDirection(deltaX, deltaY);
            update();
        }

        mouseX = newX;
        mouseY = newY;
    }
    else
    {
        QOpenGLWidget::mouseMoveEvent(event);
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    glm::vec3 movement;
    if(event->key() == Qt::Key_W)
    {
        movement.z += 1.0f;
    }
    else if(event->key() == Qt::Key_S)
    {
        movement.z -= 1.0f;
    }
    else if(event->key() == Qt::Key_D)
    {
        movement.x += 1.0f;
    }
    else if(event->key() == Qt::Key_A)
    {
        movement.x -= 1.0f;
    }
    else if(event->key() == Qt::Key_Up)
    {
        movement.y += 1.0f;
    }
    else if(event->key() == Qt::Key_Down)
    {
        movement.y -= 1.0f;
    }
    else
    {
        QOpenGLWidget::keyPressEvent(event);
    }

    renderer.GetCamera()->UpdatePosition(movement);
    update();
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    QOpenGLWidget::keyReleaseEvent(event);
}
