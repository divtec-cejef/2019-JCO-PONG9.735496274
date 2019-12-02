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
        std::cout << "add";
    } else if (tickCounter == 60*4){
        haveSuperPower = false;
        batShape.setSize(sf::Vector2f(5, 50));
        std::cout << "Stop";
        tickCounter = 0;
    }
}

void Bat::superPower(Bat *pBat, Ball *pBall, int windowWidth) {
    int bat = this->getPosition().left < windowWidth ? -1 : 1;
    if (pBall->getXVelocity() > 0) {
        // va a droite, depuis la bat gauche
        if (bat == -1) {
            pBat->malus(pBall);
        // va à droite, depuis la bat droite
        } else {
            pBat->bonus(pBall);
        }
    } else {
        // va a gauche, bat gauche
        if (bat == -1) {
            this->bonus(pBall);
        // va a gauche depuis bat droite
        } else {
            this->malus(pBall);
        }
    }
}

void Bat::malus(Ball *pBall) {
    haveSuperPower = true;
}

void Bat::bonus(Ball *pBall) {
    this->batShape.setSize(Vector2f(5, 300));
    haveSuperPower = true;
}
