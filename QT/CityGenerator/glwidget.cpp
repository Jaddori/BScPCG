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
    font = assets.loadFont("./assets/fonts/verdana_18.bin");
    fontTexture = assets.loadTexture("./assets/fonts/verdana_18.dds");

    int houseBottomSection = assets.loadModel("./assets/models/house_bot_section.model");
    int houseMiddleSection = assets.loadModel("./assets/models/house_mid_section.model");
    int houseTopSection = assets.loadModel("./assets/models/house_top_section.model");
    int houseTopSection2 = assets.loadModel("./assets/models/house_top_section2.model");

    int houseBottomTexture = assets.loadTexture("./assets/textures/concrete1.dds");
    int houseBottomTexture2 = assets.loadTexture("./assets/textures/concrete2.dds");
    int houseBottomTexture3 = assets.loadTexture("./assets/textures/concrete3.dds");
    int houseMiddleTexture = assets.loadTexture("./assets/textures/bricks1.dds");
    int houseMiddleTexture2 = assets.loadTexture("./assets/textures/bricks2.dds");
    int houseMiddleTexture3 = assets.loadTexture("./assets/textures/bricks3.dds");
    int houseTopTexture = assets.loadTexture("./assets/textures/roof1.dds");
    int houseTopTexture2 = assets.loadTexture("./assets/textures/roof2.dds");

    // initialize the noise generator
    building.setNoiseGenerator(&perlin);
    building.setDimensions(10, 10);

    // add some house bottom sections
    building.addSection(0, {houseBottomSection, houseBottomTexture}, SECTION_BOTTOM);
    building.addSection(0, {houseBottomSection, houseBottomTexture2}, SECTION_BOTTOM);
    building.addSection(0, {houseBottomSection, houseBottomTexture3}, SECTION_BOTTOM);

    // add some house middle sections
    building.addSection(0, {houseMiddleSection, houseMiddleTexture}, SECTION_MIDDLE);
    building.addSection(0, {houseMiddleSection, houseMiddleTexture2}, SECTION_MIDDLE);
    building.addSection(0, {houseMiddleSection, houseMiddleTexture3}, SECTION_MIDDLE);

    // add some house top sections
    building.addSection(0, {houseTopSection, houseTopTexture}, SECTION_TOP);
    building.addSection(0, {houseTopSection, houseTopTexture2}, SECTION_TOP);
    building.addSection(0, {houseTopSection2, houseTopTexture}, SECTION_TOP);
    building.addSection(0, {houseTopSection2, houseTopTexture2}, SECTION_TOP);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            structures.add(building.generate(0, 10, glm::vec2(i,j)));
        }
    }

    // load the renderer
    renderer.load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*for(int j=0; j<10; j++)
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
    }*/

    for(int i=0; i<structures.getSize(); i++)
    {
        Structure& s = structures[i];
        glm::vec3 position((i % 10) * 2, 0.0f, (i / 10) * 2);

        // render bottom section
        renderer.addElement(s.bottom.model, s.bottom.texture, position);
        position.y += 0.7f;

        // render middle sections
        for(int j=0; j<s.height; j++)
        {
            renderer.addElement(s.middle.model, s.middle.texture, position);
            position.y += 2.0f;
        }

        // render top section
        renderer.addElement(s.top.model, s.top.texture, position);
    }

    renderer.addText(font, fontTexture, "Testing...", glm::vec2(32.0f, 32.0f));

    renderer.render(&assets);
}

void GLWidget::resizeGL(int w, int h)
{
    renderer.getPerspectiveCamera()->updatePerspective(w, h);
    renderer.getOrthographicCamera()->updateOrthographic(w, h);
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
