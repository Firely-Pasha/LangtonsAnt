//
// Created by firely-pasha on 03.12.18.
//

#ifndef LANGTONSANT_SCENE_H
#define LANGTONSANT_SCENE_H

#include "SceneObject.h"
#include "Ant.h"
#include "Cell.h"
#include "CellType.h"
#include <array>
#include <vector>

class Scene
{
private: /* FIELDS */
    static std::vector<std::vector<Cell>> field;
    static std::vector<CellType> cellTypes;
    static std::vector<Ant> ants;

    static int width;
    static int height;

public:
    Scene();

public: /* METHODS */
    void init();
    void update();
    void render();

private: /* METHODS */

    /* FRIEND CLASSES */
    friend class Ant;
    friend class GLWidget;
    friend class Cell;
};


#endif //LANGTONSANT_SCENE_H
