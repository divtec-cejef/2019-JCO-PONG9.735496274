//
// Created by marttom on 10.12.2019.
//
#include <SFML/Graphics.hpp>

#ifndef SRC_GAMEOBJECT_H
#define SRC_GAMEOBJECT_H

using namespace sf;

//! it's the main class for object placing on the canvas
class GameObject {
protected:
    RectangleShape* shape;
    Vector2f position;
public:
    //! Constructor of GameObject
    //! \param startX contains the x position of the left of the shape
    //! \param startY contains the y position of the top of the shape
    GameObject (float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void setShape(float width, float height);

    virtual void update() = 0;
};


#endif //SRC_GAMEOBJECT_H
