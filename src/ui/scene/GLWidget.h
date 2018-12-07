//
// Created by firely-pasha on 03.12.18.
//

#ifndef LANGTONSANT_GLWIDGET_H
#define LANGTONSANT_GLWIDGET_H

#include <QtWidgets/QOpenGLWidget>
#include <QtGui/QOpenGLFunctions>
#include <src/data/config/Config.h>
#include "Scene.h"


class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT;
private: /* FIELDS */
    bool configFileLoaded;
    static Config* config;
    Scene* scene;
    bool running;
    bool isPaused;
    int frameRate;
    int skipTicks;

public:
    explicit GLWidget(char* configFilePath);
    ~GLWidget() override;

public: /* METHODS */
    void initializeGL() override;
    void run();
    void onUpdate();
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void keyPressEvent(QKeyEvent* event) override;
    bool isRunning();
    void setFrameRate(int frameRate);
    static const Config* getConfig();
    bool isConfigFileLoaded() const;
};


#endif //LANGTONSANT_GLWIDGET_H
