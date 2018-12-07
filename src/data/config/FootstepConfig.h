//
// Created by firely-pasha on 07.12.18.
//

#ifndef LANGTONSANT_FOOTSTEP_H
#define LANGTONSANT_FOOTSTEP_H


#include <QtCore/QString>
#include <array>
#include <QtCore/QJsonObject>

class FootstepConfig
{
private: /* FIELDS */
    QString rotation;
    std::array<int, 3> color;

public:
    explicit FootstepConfig(QJsonObject jsonObject = QJsonObject());

public: /* METHODS */
    const QString& getRotation() const;
    const std::array<int, 3>& getColor() const;
};


#endif //LANGTONSANT_FOOTSTEP_H
