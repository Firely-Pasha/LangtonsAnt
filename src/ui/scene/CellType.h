//
// Created by firely-pasha on 07.12.18.
//

#ifndef LANGTONSANT_CELLTYPE_H
#define LANGTONSANT_CELLTYPE_H


#include <QtCore/QString>
#include <array>

class CellType
{
private: /* FIELDS */
    std::array<int, 3> color;
    QString rotationDirection;

public:
    explicit CellType(std::array<int, 3> color = {0, 0, 0}, QString rotationDirection = "r");

public: /* METHODS */
    std::array<int, 3> getColor() const;
    QString getRotationDirection() const;
};


#endif //LANGTONSANT_CELLTYPE_H
