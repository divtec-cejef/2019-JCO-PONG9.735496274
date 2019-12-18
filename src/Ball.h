//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

//! It's the ball of pong
class Ball : public GameObject
{
private:
    float m_xVelocity = 0;
    float m_yVelocity = 0;
    Vector2f m_startPosition;


public:
    //! Constructor of ball
    //! \param startX contains the abcisse start position of the ball
    //! \param startY contains the y start position of the ball
    Ball(float startX, float startY);

    enum E_DIRECTION {
        UP_AND_DOWN,
        RIGHT_AND_LEFT
    };

    //! get the abcisse velocity of the ball
    float getXVelocity();

    //! update the ball position
    void update() override;


    void rebound(E_DIRECTION direction, bool isBat, FloatRect pBat, FloatRect pBall);

    void rebound(E_DIRECTION direction);

    void start();

    void stop();
};


#endif //PONG_BALL_H
