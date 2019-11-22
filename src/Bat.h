//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H

#include <SFML/Graphics.hpp>

using namespace sf;

//! Class Bat create a pong bat
class Bat
{
private:
    Vector2f position;

    // A RectangleShape object
    RectangleShape batShape;

    float batSpeed = 5.3f;

public:
    //! Constructor of bat
    //! \param startX contains the abcisse start position of a bat
    //! \param startY contains the y start position of a bat
    Bat(float startX, float startY);

    //! Get globalBounds sfml equivalent
    //! \return the bounds of the shape
    FloatRect getPosition();

    //! get the shape and return it
    //! \return  the shape of a bat
    RectangleShape getShape();

    //! Move the bat up
    void moveUp();

    //! move the bat down
    void moveDown();

    //! Update the position of the shape
    void update();
};


#endif //PONG_BAT_H
