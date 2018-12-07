//
// Created by firely-pasha on 07.12.18.
//

#include "Config.h"
#include <QJsonArray>

Config::Config(QJsonDocument jsonDocument)
{
    QJsonObject jsonObject = jsonDocument.object();

    title = jsonObject.value("title").toString();
    initialSpeed = jsonObject.value("initialSpeed").toInt();
    width = jsonObject.value("width").toInt();
    height = jsonObject.value("height").toInt();

    auto jsonAntConfigs = jsonObject.value("ants").toArray();
    antConfigs.reserve(static_cast<unsigned long>(jsonAntConfigs.size()));
    for (const auto& jsonAntConfig : jsonAntConfigs)
    {
        antConfigs.emplace_back(jsonAntConfig.toObject());
    }

    defaultCellType = FootstepConfig(jsonObject.value("defaultCellType").toObject());
}

const QString& Config::getTitle() const
{
    return title;
}

int Config::getInitialSpeed() const
{
    return initialSpeed;
}

int Config::getWidth() const
{
    return width;
}

int Config::getHeight() const
{
    return height;
}

const std::vector<AntConfig>& Config::getAntConfigs() const
{
    return antConfigs;
}

const FootstepConfig& Config::getDefaultCellType() const
{
    return defaultCellType;
}
