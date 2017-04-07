#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
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

    // load assets
    model = assets.LoadModel("./assets/models/valid_model.model");
    texture = assets.LoadTexture("./assets/textures/valid_texture.dds");

    // load the renderer
    renderer.Load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderer.AddElement(model, texture, glm::vec3(0.0f));
    renderer.Render(&assets);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
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
    QOpenGLWidget::mouseMoveEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    glm::vec3 cameraPosition = renderer.GetCamera()->GetPosition();
    if(event->key() == Qt::Key_W)
        cameraPosition.z += 1.0f;
    else if(event->key() == Qt::Key_S)
        cameraPosition.z -= 1.0f;
    else if(event->key() == Qt::Key_D)
        cameraPosition.x += 1.0f;
    else if(event->key() == Qt::Key_A)
        cameraPosition.x -= 1.0f;
    else if(event->key() == Qt::Key_Up)
        cameraPosition.y += 1.0f;
    else if(event->key() == Qt::Key_Down)
        cameraPosition.y -= 1.0f;
    else
        QOpenGLWidget::keyPressEvent(event);

    renderer.GetCamera()->SetPosition(cameraPosition);
    update();
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    QOpenGLWidget::keyReleaseEvent(event);
}
