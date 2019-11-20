//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
    Vector2f position;

    // A RectangleShape object
    RectangleShape batShape;

    float batSpeed = .3f;

public:
    Bat(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void update();

};


#endif //PONG_BAT_H
