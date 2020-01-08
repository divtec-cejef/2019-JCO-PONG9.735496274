//
// Created by marttom on 18.12.2019.
//
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef SRC_MIDDLELINE_H
#define SRC_MIDDLELINE_H

using namespace sf;

//! midleline of the stadium of the game
class MiddleLine {
private:
    std::vector <RectangleShape*> m_recs;
    RenderWindow* m_pWindow;
public:
    //! constructor of the midleline
    //! \param windowWidth  width of the window
    //! \param window  pointer to the window object
    MiddleLine (int windowWidth, RenderWindow* window);

    //! draw the middleline into the window
    void draw();
};


#endif //SRC_MIDDLELINE_H
