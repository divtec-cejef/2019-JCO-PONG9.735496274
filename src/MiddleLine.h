//
// Created by marttom on 18.12.2019.
//
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef SRC_MIDDLELINE_H
#define SRC_MIDDLELINE_H

using namespace sf;


class MiddleLine {
private:
    std::vector <RectangleShape*> m_recs;
    RenderWindow* m_pWindow;
public:
    MiddleLine (int windowWidth, RenderWindow* window);

    void draw();
};


#endif //SRC_MIDDLELINE_H
