//
// Created by marttom on 17.12.2019.
//

#include "ScoreViewer.h"

ScoreViewer::ScoreViewer(Vector2f position, RenderWindow *window) {
    auto* font = new Font;
    font->loadFromFile("DS-DIGIT.TTF");
    m_text = new Text();
    m_text->setCharacterSize(30);
    m_text->setString("0");
    m_text->setFont(*font);
    m_text->setPosition(position);
    m_pWindow = window;
}

int ScoreViewer::getScore() {
    return 0;
}

void ScoreViewer::addPoint() {
    m_ss.str("");
    m_ss.clear();
    m_score += 1;
    m_ss << m_score;
    m_text->setString(m_ss.str());
}

void ScoreViewer::draw() {
    m_pWindow->draw(*m_text);
}

void ScoreViewer::reset() {
}
