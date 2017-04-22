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

    // load assets
    model = assets.loadModel("./assets/models/valid_model.model");
    texture = assets.loadTexture("./assets/textures/valid_texture.dds");
    //otherTexture = assets.loadTexture("./assets/textures/other_texture.dds");
    font = assets.loadFont("./assets/fonts/verdana_18.bin");
    fontTexture = assets.loadTexture("./assets/fonts/verdana_18.dds");

    // load the renderer
    renderer.load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int j=0; j<10; j++)
    {
        glm::vec3 position(-20.0f, 0.0f, (float)(j*4));
        for(int i=0; i<10; i++)
        {
            renderer.addElement(model, texture, position);
            position.x += 4.0f;
        }
    }

    glm::vec3 position(-20.0f, 0.0f, 40.0f);
    for(int i=0; i<2; i++)
    {
        renderer.addElement(model, texture, position);
        position.x += 4.0f;
    }

    renderer.addText(font, fontTexture, "Testing...", glm::vec2(32.0f, 32.0f));

    renderer.render(&assets);
}

void GLWidget::resizeGL(int w, int h)
{
    renderer.getPerspectiveCamera()->updateProjection(w, h);
    renderer.getOrthographicCamera()->updateProjection(0.0f, (float)w, 0.0f, (float)h);
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
            renderer.getPerspectiveCamera()->updateDirection(deltaX, deltaY);
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

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mouseX = mouseY = -1;
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

    renderer.getPerspectiveCamera()->updatePosition(movement);
    update();
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    QOpenGLWidget::keyReleaseEvent(event);
}
