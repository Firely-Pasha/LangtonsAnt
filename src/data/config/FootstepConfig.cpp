//
// Created by firely-pasha on 07.12.18.
//

#include <QtCore/QJsonArray>
#include "FootstepConfig.h"

FootstepConfig::FootstepConfig(QJsonObject jsonObject)
{
    rotation = jsonObject.value("rotation").toString();
    auto jsonColor = jsonObject.value("color").toArray();
    color = {jsonColor[0].toInt(), jsonColor[1].toInt(), jsonColor[2].toInt()};
}

const QString& FootstepConfig::getRotation() const
{
    return rotation;
}

const std::array<int, 3>& FootstepConfig::getColor() const
{
    return color;
}
