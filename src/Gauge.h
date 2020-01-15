//
// Created by marttom on 17.12.2019.
//
#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef SRC_GAUGE_H
#define SRC_GAUGE_H

//! it's a gauge for show if you can use your superpower
class Gauge {
private:
    int m_maxPoint;
    float m_currentPoint = 0;
    int m_pointPerSecond;
    Vector2f m_position;
    RenderWindow* m_pWindow;
    int m_tickPerSecond;
    RectangleShape* m_pShapeIn;
    RectangleShape* m_pShapeOut;
public:
    //! Constructor of a gauge
    //! \param position contains the position (left, top) of the shape
    //! \param width contains the width of the gauge
    //! \param height contains the height of the gauge
    //! \param tickPerSecond contains the tick per second of the game
    //! \param pWindow contains the main window of the game
    //! \param maxPoint contains the maximum of point it's necessary to have for use the superpower
    //! \param pointPerSecond contains the number of point you can win in one second
    Gauge (Vector2f position, int width, int height, int tickPerSecond, RenderWindow* pWindow, int maxPoint, int pointPerSecond);

    //! can say if the gauge has full or not
    //! \return a boolean y say if the gauge are full or not
    bool isFull();

    //! reset the gauge to 0
    void use();

    //! update the value of the gauge
    void update();

    //! draw the shape into the window
    void draw ();
};


#endif //SRC_GAUGE_H
