//
// Created by marttom on 17.12.2019.
//
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

#ifndef SRC_SCOREVIEWER_H
#define SRC_SCOREVIEWER_H


class ScoreViewer {
private:
    Text* m_text;
    RenderWindow *m_pWindow;
    int m_score = 0;
    std::stringstream m_ss;
public:
    ScoreViewer(Vector2f position, RenderWindow* window);

    int getScore();

    void addPoint();

    void draw();

    void reset();
};


#endif //SRC_SCOREVIEWER_H
