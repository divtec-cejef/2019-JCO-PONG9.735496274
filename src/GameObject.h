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

    //! return the float rectangle of the shape
    FloatRect getPosition();

    //! return the shape of the object
    RectangleShape getShape();

    //! set the shape of the object
    //! if is not do, the program crash
    //! \param width the width dimension of the shape
    //! \param height the height dimension of the shape
    void setShape(float width, float height);

    //! update the position of the shape
    virtual void update() = 0;
};


#endif //SRC_GAMEOBJECT_H
