#include <utility>

#include <utility>

//
// Created by firely-pasha on 07.12.18.
//

#include "CellType.h"

CellType::CellType(std::array<int, 3> color, QString rotationDirection)
{
    CellType::color = color;
    CellType::rotationDirection = std::move(rotationDirection);
}

std::array<int, 3> CellType::getColor() const
{
    return color;
}

QString CellType::getRotationDirection() const
{
    return rotationDirection;
}
