//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    Vector2f position;

    // A RectangleShape object called ref
    RectangleShape ballShape;

    float xVelocity = 2;
    float yVelocity = 2;
    float startX = 0;
    float startY = 0;

public:
    Ball(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundWall();

    void hitBottom();

    void update();
    
    void reboundBat();

    void start();

    void stop();
};


#endif //PONG_BALL_H
