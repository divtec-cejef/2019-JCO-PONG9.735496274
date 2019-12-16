//
// Created by marttom on 20.11.2019.
//

#include "Ball.h"
#include <iostream>
#include <cstdlib>


Ball::Ball(float startX, float startY) : GameObject (startX, startY)
{
    startPosition = position;
    setShape(10, 10);
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundWall()
{
    yVelocity = -yVelocity;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // Move the ball and the bat
    shape->setPosition(position);
}

void Ball::rebound(E_DIRECTION direction, bool isBat) {
    if (isBat) {
        yVelocity > 0 ? (yVelocity += .4) : (yVelocity -= .4);
        xVelocity > 0 ? (xVelocity += .4) : (xVelocity -= .4);
    }
    if (direction == UP_AND_DOWN) {
        yVelocity = -yVelocity;
    } else {
        xVelocity = -xVelocity;
    }
}

void Ball::start() {
    xVelocity = rand()%2 == 0 ? 2 : -2;
    yVelocity = rand()%2 == 0 ? rand()%3 + 1 : 0-rand()%3 -1;
    position = startPosition;
}

void Ball::stop () {
    xVelocity = 0;
    yVelocity = 0;
    position = startPosition;
};