//
// Created by marttom on 25.10.2019.
//

#include "GameObject.h"

GameObject::GameObject(float x, float y, float scale, int width) {
    if (x >= 0 && y >= 0) {
        m_x = x;
        m_y = y;
    }
    m_scale = scale;
    m_width = width;
}

float GameObject::getX() {
    return m_x + m_width * m_scale / 2;
}

float GameObject::getY() {
    return m_y + m_width * m_scale / 2;
}

sf::Sprite* GameObject::getSprite() {
    return m_pSprite;
}

void GameObject::setSprite(sf::Texture* &texture) {
    auto* pSprite = new sf::Sprite();
    pSprite->setTexture(*texture);
    pSprite->setOrigin(0,0);
    pSprite->setScale(m_scale,m_scale);
    pSprite->setPosition(m_x, m_y);
    m_pSprite = pSprite;
}
