//
// Created by marttom on 20.11.2019.
//

#include "Ball.h"
#include <iostream>

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
    this->startX = startX;
    this->startY = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundWall()
{
    //position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // Move the ball and the bat
    ballShape.setPosition(position);
}

void Ball::reboundBat() {
    if (std::abs(xVelocity) < 5.5) {
        xVelocity += xVelocity > 0 ? .3 : -.3;
        yVelocity += yVelocity > 0 ? .3 : -.3;
    } else if (std::abs(xVelocity) < 7) {
        xVelocity += xVelocity > 0 ? .1 : -.1;
        yVelocity += yVelocity > 0 ? .1 : -.1;
    }
    xVelocity = -xVelocity;
    std::cout << xVelocity;
    std::cout << "\n";
}

void Ball::start() {
    xVelocity = 2;
    yVelocity = 2;
    position.x = startX;
    position.y = startY;
}

void Ball::stop () {
    xVelocity = 0;
    yVelocity = 0;
    position.x = startX;
    position.y = startY;
};