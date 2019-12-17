//
// Created by marttom on 17.12.2019.
//

#include "Gauge.h"

Gauge::Gauge(Vector2f position, int width, int height, int tickPerSecond, RenderWindow *pWindow, int maxPoint, int pointPerSecond) {
    m_position = position;
    m_tickPerSecond = tickPerSecond;
    m_pWindow = pWindow;
    m_maxPoint = maxPoint;
    m_pointPerSecond = pointPerSecond;

    // création des formes
    m_shapeIn = new RectangleShape(Vector2f(0, height));
    m_shapeIn->setPosition(m_position);
    m_shapeOut = new RectangleShape(Vector2f(width, height));
    m_shapeOut->setPosition(m_position);
    m_shapeOut->setOutlineThickness(5);
    m_shapeOut->setOutlineColor(Color::Green);
    m_shapeOut->setFillColor(Color::Black);
}

bool Gauge::isFull() {
    return m_maxPoint == m_currentPoint;
}

void Gauge::use() {
    m_currentPoint = 0;
    m_shapeIn->setFillColor(Color::White);
}

void Gauge::update() {
    if (m_currentPoint < m_maxPoint) {
        m_currentPoint += m_pointPerSecond / m_tickPerSecond;
        m_shapeIn->setSize(Vector2f(m_currentPoint / 600 * 100, 20));
    } else {
        m_currentPoint = m_maxPoint;
        m_shapeIn->setFillColor(Color::Green);
    }
}

void Gauge::draw() {
    m_pWindow->draw(*m_shapeOut);
    m_pWindow->draw(*m_shapeIn);
}
