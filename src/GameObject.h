//
// Created by marttom on 10.12.2019.
//
#include <SFML/Graphics.hpp>

#ifndef SRC_GAMEOBJECT_H
#define SRC_GAMEOBJECT_H

using namespace sf;


class GameObject {
protected:
    RectangleShape* shape;
    Vector2f position;
public:
    GameObject (float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void setShape(float width, float height);

    virtual void update() = 0;
};


#endif //SRC_GAMEOBJECT_H
