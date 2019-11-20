//
// Created by marttom on 02.10.2019.
//

#ifndef SRC_PLANETS_H
#define SRC_PLANETS_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Planets {
    private:
        int m_life = 100;
        std::string m_owner = "";
        int m_x;
        int m_y;
        std::string m_name;
        int m_radius;
        sf::Color m_color;
        sf::CircleShape m_planet;
        int m_actionDistance = 0;
    public:
        Planets(std::string name, int x, int y, std::string type);

        sf::CircleShape getSprite();

        int getX();

        int getY();

        std::string getName();
};



#endif //SRC_PLANETS_H
