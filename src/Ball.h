//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

//! It's the ball object of the game
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

    //! Enum for describe the direction of the rebound of the ball
    enum E_DIRECTION {
        UP_AND_DOWN,
        RIGHT_AND_LEFT
    };

    //! get the abcisse velocity of the ball
    float getXVelocity();

    //! update the ball position
    void update() override;

    //! do the rebound of the ball
    //! \param direction define the direction of the rebound
    //! \param isBat define if the ball have hit a bat
    //! \param pBat the float rectangle the bat that the ball have hurt
    //! \param pBall the float rectangle of the ball
    void rebound(E_DIRECTION direction, bool isBat, FloatRect pBat, FloatRect pBall);

    //! do the rebound of the ball
    //! \param direction define the direction of the rebound
    void rebound(E_DIRECTION direction);

    //! start the movement of the ball
    void start();

    //! stop the movement of the ball and move it to the center
    void stop();
};


#endif //PONG_BALL_H
