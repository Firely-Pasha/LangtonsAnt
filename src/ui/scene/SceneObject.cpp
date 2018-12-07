//
// Created by firely-pasha on 03.12.18.
//

#include "SceneObject.h"

SceneObject::SceneObject(QPoint position)
{
    this->position = position;
}

QPoint& SceneObject::getPosition()
{
    return position;
}

void SceneObject::setPosition(QPoint position)
{
    this->position = position;
}
