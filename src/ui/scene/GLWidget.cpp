//
// Created by firely-pasha on 03.12.18.
//

#include "GLWidget.h"
#include <QApplication>
#include <QJsonDocument>
#include <QtGui/QPainter>
#include <QtGui/QKeyEvent>
#include <iostream>
#include <QDebug>
#include <QtCore/QJsonObject>
#include <QtCore/QTime>

Config* GLWidget::config = nullptr;

GLWidget::GLWidget(char* configFilePath)
{
    QFile file;
    file.setFileName(configFilePath);
    configFileLoaded = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (configFileLoaded)
    {
        auto val = file.readAll();
        file.close();
        auto jsonConfigDocument = QJsonDocument::fromJson(val);
        config = new Config(jsonConfigDocument);
        frameRate = config->getInitialSpeed();
        skipTicks = 1000 / frameRate;
        setWindowTitle(config->getTitle());
    }
}

GLWidget::~GLWidget()
{
    delete config;
    delete scene;
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glViewport(0, 0, width(), width());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, config->getWidth(),
            0, config->getHeight(),
            0., 1.);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0);

    resize(width(), width());

    scene = new Scene();
    scene->init();
}

void GLWidget::run()
{
    QTime myTimer;
    myTimer.start();

    auto nextTick = myTimer.elapsed() + skipTicks;
    auto loops = 0;
    auto tickCount = 0;

    running = true;
    isPaused = false;

    while (isRunning())
    {
        QApplication::processEvents();
        loops = 0;
            while( myTimer.elapsed() > nextTick)
            {
                if (!isPaused)
                {
                    onUpdate();
                    std::cout << "TICK! Speed: " << frameRate << ", №: " << ++tickCount << "" << std::endl;
                }
                nextTick += skipTicks;
                loops++;
            }

        update();

        if (isHidden())
        {
            return;
        }
    }
}

void GLWidget::onUpdate()
{
    scene->update();
}

void GLWidget::paintGL()
{
    QOpenGLWidget::paintGL();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    scene->render();
}

void GLWidget::resizeGL(int w, int h)
{
    QOpenGLWidget::resizeGL(w, w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, w);
    glOrtho(0, config->getWidth(),
            0, config->getHeight(),
            0., 1.);
    
    resize(width(), width());
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    QWidget::keyPressEvent(event);

    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_E)
    {
        running = false;
    }
    else if (event->key() == Qt::Key_Space || event->key() == Qt::Key_P)
    {
        isPaused = !isPaused;
    }
    else if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_F)
    {
        setFrameRate(frameRate + 5);
    }
    else if (event->key() == Qt::Key_Minus || event->key() == Qt::Key_S)
    {
        if (frameRate > 1)
        {
            setFrameRate(frameRate - 1);
        }
    }
    else if (event->key() == Qt::Key_Equal || event->key() == Qt::Key_D)
    {
        setFrameRate(config->getInitialSpeed());
    }
}

bool GLWidget::isRunning()
{
    return running;
}

const Config* GLWidget::getConfig()
{
    return config;
}

void GLWidget::setFrameRate(int frameRate)
{
    if (frameRate >= 995)
    {
        GLWidget::frameRate = 995;
    }
    else
    {
        GLWidget::frameRate = frameRate;
    }

    skipTicks = 1000 / frameRate;
}

bool GLWidget::isConfigFileLoaded() const
{
    return configFileLoaded;
}
