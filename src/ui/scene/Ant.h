//
// Created by firely-pasha on 04.12.18.
//

#ifndef LANGTONSANT_ANT_H
#define LANGTONSANT_ANT_H


#include <src/data/config/AntConfig.h>
#include <array>
#include "SceneObject.h"

class Ant : public SceneObject
{
private: /* FIELDS */
    int rotation;
    std::array<int, 3> color;
    int cellTypeIndex;

public:
    explicit Ant(QPoint position, QString initialDirection, std::array<int, 3> color, int cellType);

public:
    void update() override;
    void render() override;

private: /* METHODS */
    int wordToAngle(QString word);
    QPoint angleToPoint(int angle);
    void checkRotation();
    void checkPosition();
};


#endif //LANGTONSANT_ANT_H
