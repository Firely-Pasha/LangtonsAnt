#include <utility>

//
// Created by firely-pasha on 04.12.18.
//

#include "Ant.h"
#include "Scene.h"
#include <QDebug>
#include <iostream>
#include <GL/gl.h>

Ant::Ant(QPoint position, QString initialDirection, std::array<int, 3> color, int cellType) : SceneObject(position)
{
    Ant::rotation = wordToAngle(std::move(initialDirection));
    Ant::position = position;
    Ant::color = color;
    Ant::cellTypeIndex = cellType;
}

void Ant::update()
{
    auto& currentCell = Scene::field[position.y()][position.x()];       // WHAT????!!!!
    auto& currentType = Scene::cellTypes[currentCell.getTypeIndex()];
    auto& antType = Scene::cellTypes[cellTypeIndex];

    rotation += wordToAngle(currentType.getRotationDirection());
    checkRotation();
    position += angleToPoint(rotation);

    if (currentCell.getTypeIndex() == cellTypeIndex)
    {
        currentCell.setTypeIndex(0);
    }
    else
    {
        currentCell.setTypeIndex(cellTypeIndex);
    }

    checkPosition();
}

void Ant::render()
{
    glPushMatrix();
        glColor3ub(static_cast<GLubyte>(color[0]), static_cast<GLubyte>(color[1]), static_cast<GLubyte>(color[2]));
        glBegin(GL_TRIANGLE_STRIP);
            glVertex2f(position.x(), position.y() + 1);
            glVertex2f(position.x(), position.y());
            glVertex2f(position.x() + 1, position.y() + 1);
            glVertex2f(position.x() + 1, position.y());
        glEnd();
    glPopMatrix();
}

int Ant::wordToAngle(QString word)
{
    if (word == "r")
    {
        return +90;
    }
    else if (word == "l")
    {
        return -90;
    }
    else if (word == "f")
    {
        return 0;
    }
    else if (word == "b")
    {
        return 180;
    }
}

QPoint Ant::angleToPoint(int angle)
{
    if (angle == 0)
    {
        return QPoint(0, 1);
    }
    else if (angle == 90)
    {
        return QPoint(1, 0);
    }
    else if (angle == 180)
    {
        return QPoint(0, -1);
    }
    else if (angle == 270)
    {
        return QPoint(-1, 0);
    }
}

void Ant::checkRotation()
{
    rotation %= 360;

    if (rotation < 0)
    {
        rotation += 360;
    }
}

void Ant::checkPosition()
{
    if (position.x() < 0) {
        position.setX(Scene::width - 1);
    }
    else if (position.x() >= Scene::width)
    {
        position.setX(0);
    }

    if (position.y() < 0) {
        position.setY(Scene::height - 1);
    }
    else if (position.y() >= Scene::width) {
        position.setY(0);
    }
}
