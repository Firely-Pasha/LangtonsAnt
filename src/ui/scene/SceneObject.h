//
// Created by firely-pasha on 03.12.18.
//

#ifndef LANGTONSANT_GAMEOBJECT_H
#define LANGTONSANT_GAMEOBJECT_H


#include <QtCore/QPoint>

class SceneObject
{
protected: /* FIELDS */
    QPoint position;

public:
    explicit SceneObject(QPoint position);

public: /* VIRTUAL METHODS */
    virtual void update() = 0;
    virtual void render() = 0;

public: /* METHODS */
    QPoint& getPosition();
    void setPosition(QPoint position);
};


#endif //LANGTONSANT_GAMEOBJECT_H
