//
// Created by firely-pasha on 07.12.18.
//

#ifndef LANGTONSANT_ANTCONFIG_H
#define LANGTONSANT_ANTCONFIG_H


#include <QtCore/QString>
#include <array>
#include <QtCore/QJsonObject>
#include <QtCore/QPoint>
#include "FootstepConfig.h"


class AntConfig
{
private: /* FIELDS */
    QString name;
    QPoint position;
    QString initialDirection;
    std::array<int, 3> color;
    FootstepConfig* footstep;

public:
    explicit AntConfig(QJsonObject jsonObject);
    ~AntConfig();

public: /* METHODS */
    const QString& getName() const;
    const QString& getInitialDirection() const;
    const QPoint& getPosition() const;
    const std::array<int, 3>& getColor() const;
    FootstepConfig* getFootstep() const;
};


#endif //LANGTONSANT_ANTCONFIG_H
