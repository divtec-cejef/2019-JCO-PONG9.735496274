//
// Created by marttom on 20.11.2019.
//

#include <iostream>
#include "Bat.h"

Bat::Bat(float startX, float startY) : GameObject(startX, startY)
{
    startPosition = position;
    setShape(5, 50);
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
    shape->setPosition(position);
    if (haveSuperPower && tickCounter < 60*4) {
        tickCounter++;
    } else if (tickCounter == 60*4){
        haveSuperPower = false;
        shape->setSize(sf::Vector2f(5, 50));
        tickCounter = 0;
    }
}

void Bat::superPower(Bat *pBat, Ball *pBall, float windowWidth) {
    if (pBat->getPosition().left > windowWidth / 2) {
        /* Bat droite est pBat*/
        if (pBall->getm_xVelocity() > 0) {
            std::cout << "bonus droit";
            pBat->bonus(pBall);
        } else {
            std::cout << "malus gauche";
            pBat->malus(pBall);
        }
    } else {
       /* Bat gauche est pBat*/
        if (pBall->getXVelocity() > 0) {
            std::cout << "malus droit";
            pBat->malus(pBall);
        } else {
            std::cout << "bonus gauche";
            pBat->bonus(pBall);
        }
    }
    std::cout << "\n";
}

void Bat::malus(Ball *pBall) {
    this->shape->setSize(Vector2f(5, 20));
    haveSuperPower = true;
}

void Bat::bonus(Ball *pBall) {
    this->shape->setSize(Vector2f(5, 300));
    haveSuperPower = true;
}
