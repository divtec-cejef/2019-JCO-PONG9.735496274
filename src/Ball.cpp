//
// Created by marttom on 20.11.2019.
//

#include "Ball.h"
#include <iostream>
#include <cstdlib>


Ball::Ball(float startX, float startY) : GameObject (startX, startY)
{
    m_startPosition = position;
    setShape(10, 10);
}

float Ball::getXVelocity()
{
    return m_xVelocity;
}

void Ball::update()
{
    // Update the ball position variablesriwrrr
    position.y += m_yVelocity;
    position.x += m_xVelocity;

    // Move the ball and the bat
    shape->setPosition(position);
}

void Ball::rebound(E_DIRECTION direction, bool isBat, FloatRect pBat, FloatRect pBall) {
    float ballMiddle = pBall.top + pBall.height / 2;
    std::cout << "m_yVelocity: " << m_yVelocity << "\n";
    if (isBat) {
        if (pBat.top + pBat.height / 5 > ballMiddle) {
            m_yVelocity -= 1;
        } else if (pBat.top + pBat.height / 5 * 2 > ballMiddle) {
            m_yVelocity -= .5;
        } else if (pBat.top + pBat.height / 5 * 3 > ballMiddle) {
        } else if (pBat.top + pBat.height / 5 * 4 > ballMiddle) {
            m_yVelocity += .5;
        } else {
            m_yVelocity += 1;
        }
        if (m_xVelocity <= 5) {
            m_xVelocity > 0 ? (m_xVelocity += .4) : (m_xVelocity -= .4);
        } else {
            m_xVelocity > 0 ? m_xVelocity = 5 : m_xVelocity = -5;
        }
    }
    rebound(direction);
}

void Ball::start() {
    m_xVelocity = rand()%2 == 0 ? 2 : -2;
    //m_yVelocity = rand()%2 == 0 ? rand()%3 + 1 : 0-rand()%3 -1;
    m_yVelocity = 0;
    position = m_startPosition;
}

void Ball::stop () {
    m_xVelocity = 0;
    m_yVelocity = 0;
    position = m_startPosition;
}

void Ball::rebound(Ball::E_DIRECTION direction) {
    if (direction == UP_AND_DOWN) {
        m_yVelocity = -m_yVelocity;
    } else {
        m_xVelocity = -m_xVelocity;
    }
}