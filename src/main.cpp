#include <QApplication>
#include <QDebug>
#include <iostream>
#include <src/ui/scene/GLWidget.h>
#include <QtCore/QTime>
#include <QtWidgets/QMessageBox>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (argc <= 1)
    {
        QMessageBox msgBox;
        msgBox.setText("Missing config file!");
        msgBox.exec();
        QApplication::exit();
        return 0;
    }

    auto* configFile = argv[1];

    QTime myTimer;
    myTimer.start();

    auto* glWidget = new GLWidget(configFile);
    if (glWidget->isConfigFileLoaded())
    {
        glWidget->show();
        glWidget->run();
    }
    else
    {

        QMessageBox msgBox;
        msgBox.setText("Couldn't open config file!");
        msgBox.exec();
        QApplication::exit();
        return 0;
    }

    return 0;
}