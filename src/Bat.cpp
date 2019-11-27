//
// Created by marttom on 20.11.2019.
//

#include <iostream>
#include "Bat.h"

Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    batShape.setSize(sf::Vector2f(5, 50));
    batShape.setPosition(position);
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
}

void Bat::superPower(Bat *pBat, Ball *pBall, int windowWidth) {
    int bat = this->getPosition().left < windowWidth ? -1 : 1;
    if (pBall->getXVelocity() > 0) {
        // va a droite, depuis la bat gauche
        if (bat == -1) {
            pBat.malus();
        // va à droite, depuis la bat droite
        } else {
            pBat.bonus();
        }
    } else {
        // va a gauche, bat gauche
        if (bat == -1) {
            
        // va a gauche depuis
        } else {

        }
        std::cout << "left";
    }
}
