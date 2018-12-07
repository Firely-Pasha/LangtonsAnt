//
// Created by firely-pasha on 07.12.18.
//

#ifndef LANGTONSANT_CONFIG_H
#define LANGTONSANT_CONFIG_H


#include <QtCore/QString>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include "AntConfig.h"

class Config
{
private: /* FIELDS */
    QString title;
    int initialSpeed;
    int width;
    int height;
    std::vector<AntConfig> antConfigs;
    FootstepConfig defaultCellType;

public:
    explicit Config(QJsonDocument jsonDocument);

public: /* METHODS */
    const QString& getTitle() const;
    int getInitialSpeed() const;
    int getWidth() const;
    int getHeight() const;
    const std::vector<AntConfig>& getAntConfigs() const;
    const FootstepConfig& getDefaultCellType() const;
};


#endif //LANGTONSANT_CONFIG_H
