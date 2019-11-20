//
// Created by marttom on 28.10.2019.
//

#include "SpaceObject.h"

SpaceObject::SpaceObject(int lifePoint, float x, float y, float scale, int width) : GameObject(x, y, scale, width) {
    std::cout << m_owner;
    if (lifePoint > 0) {
        m_lifePoint = lifePoint;
        m_maxLifePoint = lifePoint;
    }
}

void SpaceObject::setOwner(Owner* pOwner) {
        m_owner = pOwner;
        auto* texture = new sf::Texture();
        texture->loadFromFile(pOwner->getTexturePath());
        this->setSprite(texture);
}

int SpaceObject::getLifePoint() {
    return m_lifePoint;
}

void SpaceObject::addLifePoint(int number) {
    if (number > 0 && (number + m_lifePoint) <= m_maxLifePoint) {
        m_lifePoint += number;
    }
}

void SpaceObject::removeLifePoint(int number) {
    if (number > 0 && (m_lifePoint - number) >= 0) {
        m_lifePoint -= number;
    }
}

Owner* SpaceObject::getOwner() const {
    return m_owner;
}