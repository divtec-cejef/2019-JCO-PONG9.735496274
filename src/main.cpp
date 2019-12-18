#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Gauge.h"
#include "Ball.h"
#include "ScoreViewer.h"
#include "MiddleLine.h"
#include <windows.h>

#include <vector>

using namespace sf;

int main()
{
    // const definition
    const float WINDOW_WIDTH = 768;
    const float WINDOW_HEIGHT = 432;
    const sf::Time TIME_TO_PLAY = sf::seconds(3);

    // Make a window that is 768 by 432 pixels
    // And has the title "pong"
    auto* pWindow = new RenderWindow(VideoMode(static_cast<int>(WINDOW_WIDTH), static_cast<int>(WINDOW_HEIGHT)), "Pong");
    pWindow->setFramerateLimit(60);

    // create a bat
    Bat* pLeftBat = new Bat(3, WINDOW_HEIGHT / 2);
    Bat* pRightBat = new Bat(WINDOW_WIDTH - 8, WINDOW_HEIGHT / 2);
    // create a pBall
    Ball* pBall = new Ball(WINDOW_WIDTH / 2 -5, WINDOW_HEIGHT / 2);

    auto* pLeftPower = new Gauge(Vector2f(30, 10), 100, 20, 60, pWindow, 600, 60);
    auto* pRightPower = new Gauge(Vector2f(635, 10), 100, 20, 60, pWindow, 600, 60);

    auto* pLeftDisplay = new ScoreViewer(Vector2f(5, 0), pWindow);
    auto* pRightDisplay = new ScoreViewer(Vector2f(WINDOW_WIDTH - 20, 0), pWindow);

    auto* middleLine = new MiddleLine(static_cast<int>(WINDOW_WIDTH), pWindow);

    RectangleShape bigRec(sf::Vector2f(50, 50));
    bigRec.setPosition(WINDOW_WIDTH / 2, 100);

    // game loop
    while (pWindow->isOpen())
    {
        Event event{};
        while (pWindow->pollEvent(event))
        {
            if (event.type == Event::Closed)
                pWindow->close();
        }

        //\/////////////////////////////////////////
        //keyboard event
        //\/////////////////////////////////////////
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (pLeftBat->getPosition().top > 0) {
                pLeftBat->moveUp();
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (pLeftBat->getPosition().top + pLeftBat->getPosition().height < WINDOW_HEIGHT) {
                pLeftBat->moveDown();
            }
        } else if (Keyboard::isKeyPressed(Keyboard::A)) {
            if (pLeftPower->isFull()) {
                // leftPowerIn.setFillColor(Color::White);
                pLeftPower->use();
                pLeftBat->superPower(pLeftBat, pBall, WINDOW_WIDTH);
            }
        } else if (Keyboard::isKeyPressed(Keyboard::L)) {
            if (pRightPower->isFull()) {
                //rightPowerIn.setFillColor(Color::White);
                pRightPower->use();
                pRightBat->superPower(pRightBat, pBall, WINDOW_WIDTH);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))
        {
            if (pRightBat->getPosition().top > 0) {
                pRightBat->moveUp();
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            if (pRightBat->getPosition().top + pRightBat->getPosition().height < WINDOW_HEIGHT) {
                pRightBat->moveDown();
            }
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            pBall->start();
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            pWindow->close();
        }


        //\//////////////////////////////////////////////
        // Collision
        //\/////////////////////////////////////////////
        if (
                pBall->getPosition().top < 0 ||
                pBall->getPosition().top > WINDOW_HEIGHT - 10
                ) {
            pBall->rebound(pBall->UP_AND_DOWN);
        }

        // pBall hitting side right
        if (pBall->getPosition().left < 0)
        {
            pRightDisplay->addPoint();
            pBall->stop();
        }
        // pBalle hitting side right
        if (pBall->getPosition().left + 10 > WINDOW_WIDTH) {
            pLeftDisplay->addPoint();
            pBall->stop();
        }

        // pBall hit something ?
        FloatRect pB;
        if (

                pBall->getPosition().intersects((pB = pLeftBat->getPosition())) ||

                pBall->getPosition().intersects((pB = pRightBat->getPosition())) ||

                pBall->getPosition().intersects((pB = bigRec.getGlobalBounds()))

                )

        {
            bool isBat = pB.left == 3 || pB.left == 760;
            if (pBall->getPosition().top == pB.top - 8 || (pB.top + pB.height - 2 >= pBall->getPosition().top-1 && pB.top + pB.height - 2 <= pBall->getPosition().top+1)) {
                pBall->rebound(pBall->UP_AND_DOWN, isBat, pB, pBall->getPosition());
            } else  {
                pBall->rebound(pBall->RIGHT_AND_LEFT, isBat, pB, pBall->getPosition());
            }

        }

        //\//////////////////////////////////////////////
        // Update
        //\/////////////////////////////////////////////
        pBall->update();
        pLeftBat->update();
        pRightBat->update();
        pLeftPower->update();
        pRightPower->update();

        pWindow->clear(Color(0, 0, 0,0));
        //\//////////////////////////////////////////////
        // draw
        //\/////////////////////////////////////////////
        pWindow->draw(pLeftBat->getShape());
        pWindow->draw(pRightBat->getShape());
        pWindow->draw(pBall->getShape());
        pLeftPower->draw();
        pRightPower->draw();
        pLeftDisplay->draw();
        pRightDisplay->draw();
        middleLine->draw();

        pWindow->draw(bigRec);

        pWindow->display();
    }

    return 0;
}