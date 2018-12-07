#include <utility>

// Created by firely-pasha on 04.12.18.

#include <GL/gl.h>
#include "Cell.h"
#include "Scene.h"


Cell::Cell(QPoint position, int typeIndex) : SceneObject(position)
{
    Cell::typeIndex = typeIndex;
    Cell::color = Scene::cellTypes[typeIndex].getColor();
}

void Cell::update()
{

}

void Cell::render()
{
    glPushMatrix();
        glColor3ub(static_cast<GLubyte>(color[0]),
                   static_cast<GLubyte>(color[1]),
                   static_cast<GLubyte>(color[2]));
        glBegin(GL_TRIANGLE_STRIP);
            glVertex2f(position.x(), position.y() + 1);  // Справа вверху
            glVertex2f(position.x(), position.y());  // Слева внизу
            glVertex2f(position.x() + 1, position.y() + 1);  // Слева вверху
            glVertex2f(position.x() + 1, position.y());  // Справа внизу
        glEnd();
    glPopMatrix();
}

int Cell::getTypeIndex() const
{
    return typeIndex;
}

void Cell::setTypeIndex(int typeIndex)
{
    Cell::typeIndex = typeIndex;
    Cell::color = Scene::cellTypes[typeIndex].getColor();
}