//
// Created by marttom on 18.12.2019.
//

#include "MiddleLine.h"

MiddleLine::MiddleLine(int windowWidth, RenderWindow* window) {
    m_pWindow = window;
    for (int i = 0; i < 11; i++) {
        m_recs.push_back(new RectangleShape(sf::Vector2f(5, 20)));
        m_recs.at(i)->setPosition(windowWidth / 2 - 2.5, i * 40 + 5);
    }
}

void MiddleLine::draw() {
    for (RectangleShape* rec : m_recs) {
        m_pWindow->draw(*rec);
    }
}
