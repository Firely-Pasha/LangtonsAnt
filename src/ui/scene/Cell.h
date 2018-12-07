//
// Created by firely-pasha on 04.12.18.
//

#ifndef LANGTONSANT_CELL_H
#define LANGTONSANT_CELL_H


#include "SceneObject.h"
#include "CellType.h"

class Cell : public SceneObject
{
private: /* FIELDS */
    int typeIndex;
    std::array<int, 3> color;

public:
    explicit Cell(QPoint position = QPoint(0, 0), int typeIndex = 0);

public: /* METHODS */
    void update() override;
    void render() override;

public: /* METHODS */
    int getTypeIndex() const;
    void setTypeIndex(int typeIndex);
};


#endif //LANGTONSANT_CELL_H
