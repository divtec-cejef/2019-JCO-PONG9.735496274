//
// Created by marttom on 17.12.2019.
//
#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef SRC_GAUGE_H
#define SRC_GAUGE_H


class Gauge {
private:
    int m_maxPoint;
    float m_currentPoint = 0;
    int m_pointPerSecond;
    Vector2f m_position;
    RenderWindow* m_pWindow;
    int m_tickPerSecond;
    RectangleShape* m_shapeIn;
    RectangleShape* m_shapeOut;
public:
    Gauge (Vector2f position, int width, int height, int tickPerSecond, RenderWindow* pWindow, int maxPoint, int pointPerSecond);

    bool isFull();

    void use();

    void update();

    void draw ();
};


#endif //SRC_GAUGE_H
