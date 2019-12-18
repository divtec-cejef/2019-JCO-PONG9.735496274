//
// Created by marttom on 20.11.2019.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H

#include <SFML/Graphics.hpp>
#include "Ball.h"

using namespace sf;

//! Class Bat create a pong bat
class Bat : public GameObject
{
private:
    float batSpeed = 7.0f;
    bool haveSuperPower = false;
    int tickCounter = 0;

public:
    //! Constructor of bat
    //! \param startX contains the abcisse start position of a bat
    //! \param startY contains the y start position of a bat
    Bat(float startX, float startY);

    //! Move the bat up
    void moveUp();

    //! move the bat down
    void moveDown();

    //! Update the position of the shape
    void update() override;

    //! make the superpower
    //! \param pBat the bat pointer
    //! \param pBall the ball pointer
    void superPower(Bat *pBat, Ball *pBall, float windowWidth);

    //! do a malus for the bat
    //! \param pBall contain the pong ball pointer
    void malus(Ball *pBall);

    //! do a bonus for the bat
    //! \param pBall  contain the pong ball pointer
    void bonus(Ball *pBall);
};


#endif //PONG_BAT_H
