//
// Created by firely-pasha on 03.12.18.
//

#include <iostream>
#include <QDebug>
#include "Scene.h"
#include "GLWidget.h"

std::vector<std::vector<Cell>> Scene::field;
std::vector<CellType> Scene::cellTypes;
std::vector<Ant> Scene::ants;

int Scene::width;
int Scene::height;

Scene::Scene()
{
    Scene::width = GLWidget::getConfig()->getWidth();
    Scene::height = GLWidget::getConfig()->getHeight();
    auto& defaultFootstep = GLWidget::getConfig()->getDefaultCellType();
    Scene::cellTypes.emplace_back(defaultFootstep.getColor(), defaultFootstep.getRotation());
}
void Scene::init()
{
    field.reserve(static_cast<unsigned long>(height));
    for (auto j = 0; j < height; ++j)
    {
        auto row = std::vector<Cell>();
        row.reserve(static_cast<unsigned long>(width));
        for (auto i = 0; i < width; ++i)
        {
            row.emplace_back(QPoint(i, j));
        }
        field.push_back(row);
    }

    auto antConfigs = GLWidget::getConfig()->getAntConfigs();
    ants.reserve(antConfigs.size());
    cellTypes.reserve(antConfigs.size());
    for (const auto& antConfig : antConfigs)
    {
        cellTypes.emplace_back(antConfig.getFootstep()->getColor(), antConfig.getFootstep()->getRotation());
        ants.emplace_back(antConfig.getPosition(), antConfig.getInitialDirection(), antConfig.getColor(), cellTypes.size() - 1);
    }
}

void Scene::update()
{

    for (auto& ant : ants)
    {
        ant.update();
    }

    for (auto& row : field)
    {
        for (auto& cell : row)
        {
            cell.update();
        }
    }
}

void Scene::render()
{

    for (auto& ant : ants)
    {
        ant.render();
    }

    for (auto& row : field)
    {
        for (auto& cell : row)
        {
            cell.render();
        }
    }
}
