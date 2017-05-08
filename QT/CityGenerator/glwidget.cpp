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

void GLWidget::generate(const CityParameters &parameters)
{
    elicras.generate(parameters);
    update();
}

Elicras& GLWidget::getElicras()
{
    return elicras;
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

    // house sections
    int houseBottomSection = assets.loadModel("./assets/models/house_bot_section.model");
    int houseMiddleSection = assets.loadModel("./assets/models/house_mid_section.model");
    int houseTopSection = assets.loadModel("./assets/models/house_top_section.model");
    int houseTopSection2 = assets.loadModel("./assets/models/house_top_section2.model");

    // house textures
    int houseBottomTexture = assets.loadTexture("./assets/textures/concrete1.dds");
    int houseBottomTexture2 = assets.loadTexture("./assets/textures/concrete2.dds");
    int houseBottomTexture3 = assets.loadTexture("./assets/textures/concrete3.dds");
    int houseMiddleTexture = assets.loadTexture("./assets/textures/bricks1.dds");
    int houseMiddleTexture2 = assets.loadTexture("./assets/textures/bricks2.dds");
    int houseMiddleTexture3 = assets.loadTexture("./assets/textures/bricks3.dds");
    int houseTopTexture = assets.loadTexture("./assets/textures/roof1.dds");
    int houseTopTexture2 = assets.loadTexture("./assets/textures/roof2.dds");

    // skyscraper sections
    int skyBottomSection = assets.loadModel("./assets/models/skyscraper_bot_section.model");
    int skyMiddleSection = assets.loadModel("./assets/models/skyscraper_mid_section.model");
    int skyTopSection = assets.loadModel("./assets/models/skyscraper_top_section.model");

    // skyscraper textures
    int skyBottomTexture = houseBottomTexture;
    int skyBottomTexture2 = houseBottomTexture2;
    int skyBottomTexture3 = houseBottomTexture3;
    int skyMiddleTexture = assets.loadTexture("./assets/textures/skyscraper1.dds");
    int skyMiddleTexture2 = assets.loadTexture("./assets/textures/skyscraper2.dds");
    int skyMiddleTexture3 = assets.loadTexture("./assets/textures/skyscraper3.dds");
    int skyMiddleTexture4 = assets.loadTexture("./assets/textures/skyscraper4.dds");
    int skyMiddleTexture5 = assets.loadTexture("./assets/textures/skyscraper5.dds");
    int skyTopTexture = houseBottomTexture;
    int skyTopTexture2 = houseBottomTexture2;
    int skyTopTexture3 = houseBottomTexture3;

    // factory sections
    /*int factoryBottomSection = assets.loadModel("./assets/models/factory_bot_section.model");
    int factoryMiddleSection = assets.loadModel("./assets/models/factory_mid_section.model");
    int factoryTopSection = assets.loadModel("./assets/models/factory_top_section.model");*/
    int factoryBottomSection = houseBottomSection;
    int factoryMiddleSection = houseMiddleSection;
    int factoryTopSection = houseTopSection;

    int factoryBottomTexture = houseBottomTexture;
    int factoryMiddleTexture = houseMiddleTexture;
    int factoryTopTexture = houseBottomTexture;

    elicras.setDimensions(CITY_WIDTH, CITY_HEIGHT);

    // add some house bottom sections
    elicras.addBuildingSection(0, {houseBottomSection, houseBottomTexture}, SECTION_BOTTOM);
    elicras.addBuildingSection(0, {houseBottomSection, houseBottomTexture2}, SECTION_BOTTOM);
    elicras.addBuildingSection(0, {houseBottomSection, houseBottomTexture3}, SECTION_BOTTOM);

    // add some house middle sections
    elicras.addBuildingSection(0, {houseMiddleSection, houseMiddleTexture}, SECTION_MIDDLE);
    elicras.addBuildingSection(0, {houseMiddleSection, houseMiddleTexture2}, SECTION_MIDDLE);
    elicras.addBuildingSection(0, {houseMiddleSection, houseMiddleTexture3}, SECTION_MIDDLE);

    // add some house top sections
    elicras.addBuildingSection(0, {houseTopSection, houseTopTexture}, SECTION_TOP);
    elicras.addBuildingSection(0, {houseTopSection, houseTopTexture2}, SECTION_TOP);
    elicras.addBuildingSection(0, {houseTopSection2, houseTopTexture}, SECTION_TOP);
    elicras.addBuildingSection(0, {houseTopSection2, houseTopTexture2}, SECTION_TOP);

    // add some skyscraper bottom sections
    elicras.addBuildingSection(1, {skyBottomSection, skyBottomTexture}, SECTION_BOTTOM);
    elicras.addBuildingSection(1, {skyBottomSection, skyBottomTexture2}, SECTION_BOTTOM);
    elicras.addBuildingSection(1, {skyBottomSection, skyBottomTexture3}, SECTION_BOTTOM);

    // add some skyscraper middle sections
    elicras.addBuildingSection(1, {skyMiddleSection, skyMiddleTexture}, SECTION_MIDDLE);
    elicras.addBuildingSection(1, {skyMiddleSection, skyMiddleTexture2}, SECTION_MIDDLE);
    elicras.addBuildingSection(1, {skyMiddleSection, skyMiddleTexture3}, SECTION_MIDDLE);
    elicras.addBuildingSection(1, {skyMiddleSection, skyMiddleTexture4}, SECTION_MIDDLE);
    elicras.addBuildingSection(1, {skyMiddleSection, skyMiddleTexture5}, SECTION_MIDDLE);

    // add some skyscraper top sections
    elicras.addBuildingSection(1, {skyTopSection, skyTopTexture}, SECTION_TOP);
    elicras.addBuildingSection(1, {skyTopSection, skyTopTexture2}, SECTION_TOP);
    elicras.addBuildingSection(1, {skyTopSection, skyTopTexture3}, SECTION_TOP);

    // add skyscraper height
    elicras.loadAssets(&assets);

    // add some factory bottom sections
    elicras.addBuildingSection(2, {factoryBottomSection, factoryBottomTexture}, SECTION_BOTTOM);

    // add some factory middle sections
    elicras.addBuildingSection(2, {factoryMiddleSection, factoryMiddleTexture}, SECTION_MIDDLE);

    // add some factory top sections
    elicras.addBuildingSection(2, {factoryTopSection, factoryTopTexture}, SECTION_TOP);

    // load the renderer
    renderer.load();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    elicras.render(&renderer);

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
