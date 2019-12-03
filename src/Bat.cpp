//
// Created by marttom on 20.11.2019.
//

#include <iostream>
#include "Bat.h"

Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
    startPosition = position;

    batShape.setSize(sf::Vector2f(5, 50));
    batShape.setPosition(startPosition);
}

FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
    return batShape;
}

void Bat::moveUp()
{
    position.y -= batSpeed;
}

void Bat::moveDown()
{
    position.y += batSpeed;
}

void Bat::update()
{
    batShape.setPosition(position);
    if (haveSuperPower && tickCounter < 60*4) {
        tickCounter++;
    } else if (tickCounter == 60*4){
        haveSuperPower = false;
        batShape.setSize(sf::Vector2f(5, 50));
        tickCounter = 0;
    }
}

void Bat::superPower(Bat *pBat, Ball *pBall, float windowWidth) {
    if (pBat->getPosition().left > windowWidth / 2) {
        /* Bat droite est pBat*/
        if (pBall->getXVelocity() > 0) {
            std::cout << "droit";
        } else {
            std::cout << "gauche";
        }
    } else {
       /* Bat gauche est pBat*/
    }
}

void Bat::malus(Ball *pBall) {
    this->batShape.setSize(Vector2f(5, 20));
    haveSuperPower = true;
}

void Bat::bonus(Ball *pBall) {
    this->batShape.setSize(Vector2f(5, 300));
    haveSuperPower = true;
}
