//
// Created by marttom on 17.12.2019.
//
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

#ifndef SRC_SCOREVIEWER_H
#define SRC_SCOREVIEWER_H

//! Displayer of the score
//! this class is util for
class ScoreViewer {
private:
    Text* m_pText;
    RenderWindow *m_pWindow;
    int m_score = 0;
    std::stringstream m_ss;
public:
    //! constructor of the score viewer
    //! \param position of the shape
    //! \param window contain a pointer to the main window
    ScoreViewer(Vector2f position, RenderWindow* window);

    //! get the score of the scoreViewer
    //! \return an int contains the score
    int getScore();

    //! add one point to the score
    void addPoint();

    //! draw the shape into the main window
    void draw();

    //! reset the score to 0
    void reset();
};


#endif //SRC_SCOREVIEWER_H
