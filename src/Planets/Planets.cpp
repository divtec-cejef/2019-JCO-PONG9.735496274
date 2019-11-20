//
// Created by marttom on 02.10.2019.
//

#include "Planets.h"

Planets::Planets (std::string name, int x, int y, std::string type) {
    m_name = name;
    m_x = x;
    m_y = y;
    if (type == "p") {
        m_radius = 60;
        m_color = sf::Color::Cyan;
        m_actionDistance = 100;
    } else if (type == "m") {
        m_radius = 40;
        m_color = sf::Color::Blue;
        m_actionDistance = 90;
    } else {
        m_radius = 20;
        m_color = sf::Color::Green;
        m_actionDistance = 80;
    }
    sf::CircleShape planet(m_radius);
    planet.setFillColor(m_color);
    planet.setOrigin(0, 0);
    planet.setPosition(m_x, m_y);
    m_planet = planet;
}

sf::CircleShape Planets::getSprite () {
    return m_planet;
}

int Planets::getX () {
    return m_x + m_radius;
}

int Planets::getY () {
    return m_y + m_radius;
}

std::string Planets::getName () {
    return m_name;
}
