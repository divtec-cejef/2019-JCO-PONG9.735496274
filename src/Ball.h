//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics.hpp>

using namespace sf;

//! It's the ball of pong
class Ball
{
private:
    Vector2f position;

    RectangleShape ballShape;

    float xVelocity = 2;
    float yVelocity = 2;
    float startX = 0;
    float startY = 0;

public:
    //! Constructor of ball
    //! \param startX contains the abcisse start position of the ball
    //! \param startY contains the y start position of the ball
    Ball(float startX, float startY);

    //! get the global bounds of the ball
    FloatRect getPosition();

    //! get the shape of the ball
    RectangleShape getShape();

    //! get the abcisse velocity of the ball
    float getXVelocity();

    //! inverse the y velocity of the ball
    void reboundWall();

    //! update the ball position
    void update();


    void reboundBat();

    void start();

    void stop();
};


#endif //PONG_BALL_H
