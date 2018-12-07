//
// Created by firely-pasha on 07.12.18.
//

#include "AntConfig.h"
#include <QJsonArray>

AntConfig::AntConfig(QJsonObject jsonObject)
{
    AntConfig::name = jsonObject.value("name").toString();
    AntConfig::initialDirection = jsonObject.value("initialDirection").toString();
    auto jsonPosition = jsonObject.value("position").toArray();
    AntConfig::position = QPoint(jsonPosition[0].toInt(), jsonPosition[1].toInt());
    auto jsonColor = jsonObject.value("color").toArray();
    AntConfig::color = {jsonColor[0].toInt(), jsonColor[1].toInt(), jsonColor[2].toInt()};
    AntConfig::footstep = new FootstepConfig(jsonObject.value("footstep").toObject());
}

AntConfig::~AntConfig()
{
    delete(footstep);
}

const QString& AntConfig::getName() const
{
    return name;
}

const QPoint& AntConfig::getPosition() const
{
    return position;
}

const QString& AntConfig::getInitialDirection() const
{
    return initialDirection;
}

const std::array<int, 3>& AntConfig::getColor() const
{
    return color;
}

FootstepConfig* AntConfig::getFootstep() const
{
    return footstep;
}
